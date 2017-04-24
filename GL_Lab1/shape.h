#ifndef SHAPE_H
#define SHAPE_H

#include <QColor>
#include <QOpenGLFunctions>

class Shape
{
public:
    virtual void draw(QOpenGLFunctions *f, GLuint *m_colAttr);

private:
    //float* vertices;
    float color[4];
};

#endif // SHAPE_H
