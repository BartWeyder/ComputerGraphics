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

    //f = QOpenGLContext::currentContext()->functions();

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
    /*Triangle * newTriangle = new Triangle (50, 50, this->width(), this->height(), this->pickedColor);
    Triangle * newTriangle1 = new Triangle (500, 200, this->width(), this->height(), this->pickedColor);
    Square * newSquare = new Square (250, 250, this->width(), this->height(), this->pickedColor);
    NonConvex * newNonConvex = new NonConvex(250, 200, this->width(), this->height(), this->pickedColor);
    SandWatch * newSandWatch = new SandWatch(350, 290, this->width(), this->height(), this->pickedColor);

    newTriangle->draw(f, &m_colAttr);
    newTriangle1->draw(f, &m_colAttr);
    newSquare->draw(f, &m_colAttr);
    newNonConvex->draw(f, &m_colAttr);
    newSandWatch->draw(f, &m_colAttr);*/
    if(needDraw)
    {
        m_program->bind();
        switch (currentShape) {
        case 0:
        {
            Triangle * t = new Triangle (this->currentX, this->currentY, width(), height(), this->pickedColor);
            t->draw(f, &m_colAttr);
            delete t;
            break;
        }
        case 1:
        {
            Square * s = new Square (this->currentX, this->currentY, width(), height(), this->pickedColor);
            s->draw(f, &m_colAttr);
            delete s;
        }
        case 2:
        {
            NonConvex * nc = new NonConvex (this->currentX, this->currentY, width(), height(), this->pickedColor);
            nc->draw(f, &m_colAttr);
            delete nc;
        }
        case 3:
        {
            SandWatch * sw = new SandWatch (this->currentX, this->currentY, width(), height(), this->pickedColor);
            sw->draw(f, &m_colAttr);
            delete sw;
        }
        default:
            break;
        }
        m_program->release();
    }
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
