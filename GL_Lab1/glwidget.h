#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLContext>
#include <QOpenGLShader>
#include <QColor>
#include <list>
#include "shape.h"

class GLWidget : public QOpenGLWidget//, protected QOpenGLFunctions
{
private:
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo;
    QOpenGLFunctions *f;
    bool needInit = true;
    std::list <Shape*> shapeList;
    GLuint m_colAttr;

    QOpenGLContext *m_context;
    QOpenGLShaderProgram *m_program;
    QOpenGLShader *m_shader;

    const GLchar* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 position;\n"
        "layout (location = 1) in vec3 color;\n"
        "void main()\n"
        "{\n"
        "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
        "outColor = color;\n"
        "}\0";
    const GLchar* fragmentShaderSource = "#version 330 core\n"
        "out vec4 color;\n"
        "uniform vec4 outColor;\n"
        "void main()\n"
        "{\n"
        "color = outColor;\n"
        "}\n\0";
public:
    explicit GLWidget(QWidget *parent);
    ~GLWidget();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void setPickedColor(QColor color);
protected:
    QColor pickedColor;
};

#endif // GLWIDGET_H
