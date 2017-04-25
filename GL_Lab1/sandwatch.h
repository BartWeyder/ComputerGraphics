#ifndef SANDWATCH_H
#define SANDWATCH_H

#include "shape.h"


class SandWatch : public Shape
{
public:
    SandWatch(int x, int y, int width, int height, QColor pickedColor);
    ~SandWatch();
    void draw(QOpenGLFunctions *f, GLuint *m_colAttr) override;
private:
    float vertices[15];
    float color[4];
};

#endif // SANDWATCH_H
