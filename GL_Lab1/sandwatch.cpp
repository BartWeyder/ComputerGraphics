#include "sandwatch.h"

SandWatch::SandWatch(int x, int y, int width, int height, QColor pickedColor)
{
    float stepX = 0;
    float stepY = 0;
    for (int i = 0; i < 5; i++)
    {
        this->vertices[i*3] = (2.0f * (x + stepX)) / width - 1.0f;
        this->vertices[i*3 + 1] = 1.0f - (2.0f * (y + stepY)) / height;
        this->vertices[i*3 + 2] = 0.0f;

        switch (i) {
        case 0:
            stepX -= 25;
            stepY += 25;
            break;
        case 1:
            stepX += 50;
            break;
        case 2:
            stepY -= 50;
            break;
        case 3:
            stepX -= 50;
        default:
            break;
        }
    }

    this->color[0] = (float) pickedColor.redF();
    this->color[1] = (float) pickedColor.greenF();
    this->color[2] = (float) pickedColor.blueF();
    this->color[3] = (float) pickedColor.alphaF();
}

SandWatch::~SandWatch() { }

void SandWatch::draw(QOpenGLFunctions *f, GLuint *m_colAttr)
{
    GLuint VBO, EBO;
    GLuint indices[] =
    {
        0, 1, 2,
        0, 3, 4
    };

    f->glGenBuffers(1, &VBO);
    f->glGenBuffers(1, &EBO);

    f->glBindBuffer(GL_ARRAY_BUFFER, VBO);
    f->glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);

    f->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    f->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    f->glUniform4f(*m_colAttr, 0.0, 1.0, 0.5, 0.0);
    f->glEnableVertexAttribArray(0);
    f->glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    f->glDisableVertexAttribArray(0);

    f->glDeleteBuffers(1, &VBO);
    f->glDeleteBuffers(1, &EBO);
}
