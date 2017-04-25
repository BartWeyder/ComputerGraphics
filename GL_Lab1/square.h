#ifndef SQUARE_H
#define SQUARE_H

#include <QColor>
#include"shape.h"

class Square : public Shape
{
public:
    Square(int x, int y, int width, int height, QColor pickedColor);
    ~Square();
    void draw(QOpenGLFunctions *f, GLuint *m_colAttr) override;
private:
    float vertices[12];
    float color[4];
};

#endif // SQUARE_H
