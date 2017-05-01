#include "glwidget.h"
#include <QSurface>
#include <QMouseEvent>
#include <QOpenGLContext>

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) { }

GLWidget::~GLWidget()
{
    makeCurrent();

    delete m_shader;
    delete m_program;
    delete f;

    m_vbo.destroy();
    m_vao.destroy();

    doneCurrent();
}
void GLWidget::initializeGL()
{
    if (needInit)
    {
        f = new QOpenGLFunctions;
        f->initializeOpenGLFunctions();
        f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        f->glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        needInit = false;
    }
    this->m_program = new QOpenGLShaderProgram(this);
    this->m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    this->m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    this->m_program->link();
    this->m_colAttr = m_program->uniformLocation("outColor");
}

void GLWidget::resizeGL(int w, int h)
{
    const qreal retinaScale = devicePixelRatio();
    f->glViewport(0, 0, width() * retinaScale, height() * retinaScale);
}

void GLWidget::paintGL()
{
    Triangle * t;
    Square * s;
    NonConvex * nc;
    SandWatch * sw;

    m_program->bind();
    drawList();
    if(needDraw)
    {
        switch (currentShape) {
        case 0:
            t = new Triangle (this->currentX, this->currentY, width(), height(), this->pickedColor);
            t->draw(f, &m_colAttr);
            this->list.push_back(t);
            break;
        case 1:
            s = new Square (this->currentX, this->currentY, width(), height(), this->pickedColor);
            s->draw(f, &m_colAttr);
            this->list.push_back(s);
            break;
        case 2:
            nc = new NonConvex (this->currentX, this->currentY, width(), height(), this->pickedColor);
            nc->draw(f, &m_colAttr);
            this->list.push_back(nc);
            break;
        case 3:
            sw = new SandWatch (this->currentX, this->currentY, width(), height(), this->pickedColor);
            sw->draw(f, &m_colAttr);
            this->list.push_back(sw);
            break;
        default:
            break;
        }
        this->needDraw = false;
    }
    m_program->release();
}

void GLWidget::setPickedColor(QColor color)
{
    this->pickedColor = color;
}

void GLWidget::setColorMix(int mix)
{
    this->colorMix = mix;
}

void GLWidget::setCurrentShape(int shape)
{
    this->currentShape = shape;
}

void GLWidget::setNot(bool n)
{
    this->n = n;
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        currentX = event->x();
        currentY = event->y();
        this->needDraw = true;
        update();
    }
}

void GLWidget::drawList()
{
    std::list<Shape*>::const_iterator iterator;
    for (iterator = this->list.begin(); iterator != this->list.end(); iterator++)
    {
        (*iterator)->draw(f, &m_colAttr);
    }
}
