#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QColor>
#include <QOpenGLFunctions>
#include "shape.h"

class Triangle : public Shape
{
public:
    Triangle(int x, int y, int width, int height, QColor pickedColor);
    ~Triangle();
    void draw (QOpenGLFunctions *f, GLuint *m_colAttr) override;
private:
    float vertices[9];
    float color[4];
};

#endif // TRIANGLE_H
