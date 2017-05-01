#include "triangle.h"
#include <QColor>
#include <stdlib.h>

Triangle::Triangle(int x, int y, int width, int height, QColor pickedColor)
{
    int stepX = -25;
    int stepY = -25;

    //this->vertices = new float[9];

    for(int i = 0; i < 3; i++) {
        this->vertices[i*3] = (2.0f * (x + stepX)) / width - 1.0;
        this->vertices[i*3 + 1] = 1.0f - (2.0f * (y + stepY)) / height;
        this->vertices[i*3 + 2] = 0.0f;
        switch (i) {
        case 0:
            stepX += 25;
            stepY += 50;
            break;
        case 1:
            stepX += 25;
            stepY -= 50;
            break;
        default:
            break;
        }
    }
    this->color[0] = (float) pickedColor.redF();
    this->color[1] = (float) pickedColor.greenF();
    this->color[2] = (float) pickedColor.blueF();
    this->color[3] = (float) pickedColor.alphaF();
}

Triangle::~Triangle()
{
}

void Triangle::draw(QOpenGLFunctions *f, GLuint *m_colAttr)
{
    GLuint VBO, EBO;
    GLuint indices[] = {0, 1, 2};

    f->glGenBuffers(1, &VBO);
    f->glGenBuffers(1, &EBO);

    f->glBindBuffer(GL_ARRAY_BUFFER, VBO);
    f->glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);

    f->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    f->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    f->glUniform4f(*m_colAttr, this->color[0], this->color[1], this->color[2], this->color[3]);
    f->glEnableVertexAttribArray(0);
    f->glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

    f->glDisableVertexAttribArray(0);

    f->glDeleteBuffers(1, &VBO);
    f->glDeleteBuffers(1, &EBO);
}
