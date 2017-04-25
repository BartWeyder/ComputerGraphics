#ifndef NONCONVEX_H
#define NONCONVEX_H

#include "shape.h"


class NonConvex : public Shape
{
public:
    NonConvex(int x, int y, int width, int height, QColor pickedColor);
    ~NonConvex();
    void draw(QOpenGLFunctions *f, GLuint *m_colAttr) override;
private:
    float vertices[12];
    float color[4];
};

#endif // NONCONVEX_H
