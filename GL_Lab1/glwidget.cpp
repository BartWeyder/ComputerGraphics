#include "glwidget.h"
#include "triangle.h"
#include <QSurface>

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
    /*m_context = new QOpenGLContext(this->parent());

    m_context = new QOpenGLContext(this);
    m_context->setFormat(requestedFormat());
    m_context->create();*/

    //m_context->makeCurrent(this);

    //m_context = QOpenGLWidget::context();

    if (needInit)
    {
        f = new QOpenGLFunctions;
        f->initializeOpenGLFunctions();
        needInit = false;
    }

    f = QOpenGLContext::currentContext()->functions();

    this->m_program = new QOpenGLShaderProgram(this);
    this->m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    this->m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    this->m_program->link();
    this->m_colAttr = m_program->uniformLocation("outColor");

    f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    f->glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

}

void GLWidget::resizeGL(int w, int h)
{

}

void GLWidget::paintGL()
{
    const qreal retinaScale = devicePixelRatio();
    f->glViewport(0, 0, width() * retinaScale, height() * retinaScale);
    m_program->bind();
    //std::list <Shape*>::iterator iterator;
    Triangle * newTriangle = new Triangle (50, 50, this->width(), this->height(), this->pickedColor);
    Triangle * newTriangle1 = new Triangle (500, 200, this->width(), this->height(), this->pickedColor);
    newTriangle->draw(f, &m_colAttr);
    newTriangle1->draw(f, &m_colAttr);
    m_program->release();
    //m_context->swapBuffers();
}

void GLWidget::setPickedColor(QColor color)
{
    this->pickedColor = color;
}

