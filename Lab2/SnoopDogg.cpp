#include "SnoopDogg.h"
#include <vector>


SnoopDogg::SnoopDogg()
{
	ourShader = new Shader("SnoopDogg.vs", "SnoopDogg.frag");
	initBody();
}


SnoopDogg::~SnoopDogg()
{
}

void SnoopDogg::drawSnoopDogg()
{
	//doit later
}

/*
Generates body vertices into bodyVertices array.
*/
void SnoopDogg::initBody()
{
	std::vector<GLfloat> vertices, boxVertices;
	//boots
	boxVertices = this->getBoxVertices(-0.25f, -0.8f, -WIDTH / 2, 0.25f, 0.2f, WIDTH + 0.1f,
		71 / 255.0f, 45 / 255.0f, 10 / 255.0f, false);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	boxVertices = this->getBoxVertices(0.0f, -0.8f, -WIDTH / 2, 0.25f, 0.2f, WIDTH + 0.1f,
		71 / 255.0f, 45 / 255.0f, 10 / 255.0f, false);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	//legs
	boxVertices = this->getBoxVertices(-0.25f, -0.6f, -WIDTH / 2, 0.25f, 0.6f, WIDTH,
		17 / 255.0f, 13 / 255.0f, 68 / 255.0f, false);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	boxVertices = this->getBoxVertices(0.0f, -0.6f, -WIDTH / 2, 0.25f, 0.6f, WIDTH,
		17 / 255.0f, 13 / 255.0f, 68 / 255.0f, false);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	//body
	boxVertices = this->getBoxVertices(-0.25f, 0.0f, -WIDTH / 2, 0.5f, 0.5f, WIDTH, 0, 0, 0, true);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	//arms
	boxVertices = this->getBoxVertices(-0.65f, 0.4f, -WIDTH / 2, 0.4f, 0.1f, WIDTH, 0, 0, 0, true);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	boxVertices = this->getBoxVertices(0.25f, 0.4f, -WIDTH / 2, 0.4f, 0.1f, WIDTH, 0, 0, 0, true);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	//hands
	boxVertices = this->getBoxVertices(-0.75f, 0.4f, -WIDTH / 2, 0.1f, 0.1f, WIDTH,
		236 / 255.0f, 155 / 255.0f, 74 / 255.0f, false);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	boxVertices = this->getBoxVertices(0.65f, 0.4f, -WIDTH / 2, 0.1f, 0.1f, WIDTH,
		236 / 255.0f, 155 / 255.0f, 74 / 255.0f, false);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	//sax
	boxVertices = this->getBoxVertices(-0.73f, 0.5f, 0, 0.05f, 0.05f, WIDTH,
		67 / 255.0f, 204 / 255.0f, 243 / 255.0f, false);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	boxVertices = this->getBoxVertices(-0.73f, 0.55f, WIDTH - 0.05f, 0.05f, 0.05f, 0.05f,
		67 / 255.0f, 204 / 255.0f, 243 / 255.0f, false);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	//transform to array
	std::copy(vertices.begin(), vertices.end(), this->bodyVertices);
	//clear memory. do we need to do this?
	vertices.erase(vertices.begin(), vertices.end());
	boxVertices.erase(boxVertices.begin(), boxVertices.end());
}

void SnoopDogg::initHead()
{
}

/**
* Generates sides of cube (adjaced to point(x,y,z) and point(x+w, y+h, y+d))
* I'm too lazy, so I won't make overload here and if u want use toxic camo you need to enter
* colors anyway :p
*/
std::vector<GLfloat> SnoopDogg::getBoxVertices(GLfloat x, GLfloat y, GLfloat z,
	GLfloat width, GLfloat height, GLfloat depth,
	GLfloat colorX, GLfloat colorY, GLfloat colorZ, bool toxic)
{
	std::vector<GLfloat> verticesVector;
	std::vector<GLfloat> squareVector;
	if (toxic)
	{
		squareVector = this->getSquareVertices(x, y, z, width, height, 0);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
		squareVector = this->getSquareVertices(x, y, z, width, 0, depth);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
		squareVector = this->getSquareVertices(x, y, z, 0, height, depth);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
		squareVector = this->getSquareVertices(
			x + width, y + height, z + depth, -width, -height, 0);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
		squareVector = this->getSquareVertices(
			x + width, y + height, z + depth, -width, 0, -depth);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
		squareVector = this->getSquareVertices(
			x + width, y + height, z + depth, 0, -height, -depth);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
	}
	else
	{
		squareVector = this->getSquareVertices(x, y, z, width, height, 0, colorX, colorY, colorZ);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
		squareVector = this->getSquareVertices(x, y, z, width, 0, depth, colorX, colorY, colorZ);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
		squareVector = this->getSquareVertices(x, y, z, 0, height, depth, colorX, colorY, colorZ);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
		squareVector = this->getSquareVertices(
			x + width, y + height, z + depth, -width, -height, 0, colorX, colorY, colorZ);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
		squareVector = this->getSquareVertices(
			x + width, y + height, z + depth, -width, 0, -depth, colorX, colorY, colorZ);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
		squareVector = this->getSquareVertices(
			x + width, y + height, z + depth, 0, -height, -depth, colorX, colorY, colorZ);
		verticesVector.insert(verticesVector.end(), squareVector.begin(), squareVector.end());
	}
	return verticesVector;
}

/*
Generates Square Vertices. Point(x,y,z) is left-down-back point of square.
*/
std::vector<GLfloat> SnoopDogg::getSquareVertices(GLfloat x, GLfloat y, GLfloat z,
	GLfloat width, GLfloat height, GLfloat depth, 
	GLfloat colorX, GLfloat colorY, GLfloat colorZ)
{
	std::vector<GLfloat> vertices;
	vertices.push_back(x);
	vertices.push_back(y);
	vertices.push_back(z);
	vertices.push_back(colorX);
	vertices.push_back(colorY);
	vertices.push_back(colorZ);

	if (width == 0)
	{
		vertices.push_back(x);
		vertices.push_back(y + height);
		vertices.push_back(z);
		vertices.push_back(colorX);
		vertices.push_back(colorY);
		vertices.push_back(colorZ);

		for (int i = 0; i < 2; i++)
		{
			vertices.push_back(x);
			vertices.push_back(y + height);
			vertices.push_back(z + depth);
			vertices.push_back(colorX);
			vertices.push_back(colorY);
			vertices.push_back(colorZ);
		}

		vertices.push_back(x);
		vertices.push_back(y);
		vertices.push_back(z + depth);
		vertices.push_back(colorX);
		vertices.push_back(colorY);
		vertices.push_back(colorZ);
	}

	if (height == 0)
	{
		vertices.push_back(x + width);
		vertices.push_back(y);
		vertices.push_back(z);
		vertices.push_back(colorX);
		vertices.push_back(colorY);
		vertices.push_back(colorZ);

		for (int i = 0; i < 2; i++)
		{
			vertices.push_back(x + width);
			vertices.push_back(y);
			vertices.push_back(z + depth);
			vertices.push_back(colorX);
			vertices.push_back(colorY);
			vertices.push_back(colorZ);
		}

		vertices.push_back(x);
		vertices.push_back(y);
		vertices.push_back(z + depth);
		vertices.push_back(colorX);
		vertices.push_back(colorY);
		vertices.push_back(colorZ);
	}

	if (depth == 0)
	{
		vertices.push_back(x);
		vertices.push_back(y + height);
		vertices.push_back(z);
		vertices.push_back(colorX);
		vertices.push_back(colorY);
		vertices.push_back(colorZ);

		for (int i = 0; i < 2; i++)
		{
			vertices.push_back(x + width);
			vertices.push_back(y + height);
			vertices.push_back(z);
			vertices.push_back(colorX);
			vertices.push_back(colorY);
			vertices.push_back(colorZ);
		}

		vertices.push_back(x + width);
		vertices.push_back(y);
		vertices.push_back(z);
		vertices.push_back(colorX);
		vertices.push_back(colorY);
		vertices.push_back(colorZ);
	}

	vertices.push_back(x);
	vertices.push_back(y);
	vertices.push_back(z);
	vertices.push_back(colorX);
	vertices.push_back(colorY);
	vertices.push_back(colorZ);
	return vertices;
}

/*
Uses auto-toxic colors.
*/
std::vector<GLfloat> SnoopDogg::getSquareVertices(GLfloat x, GLfloat y, GLfloat z, 
		GLfloat width, GLfloat height, GLfloat depth)

	{
		std::vector<GLfloat> vertices;
		vertices.push_back(x);
		vertices.push_back(y);
		vertices.push_back(z);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);

		if (width == 0)
		{
			vertices.push_back(x);
			vertices.push_back(y + height);
			vertices.push_back(z);
			vertices.push_back(0.0f);
			vertices.push_back(1.0f);
			vertices.push_back(0.0f);

			for (int i = 0; i < 2; i++)
			{
				vertices.push_back(x);
				vertices.push_back(y + height);
				vertices.push_back(z + depth);
				vertices.push_back(0.0f);
				vertices.push_back(0.0f);
				vertices.push_back(1.0f);
			}

			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z + depth);
			vertices.push_back(0.0f);
			vertices.push_back(1.0f);
			vertices.push_back(0.0f);
		}

		if (height == 0)
		{
			vertices.push_back(x + width);
			vertices.push_back(y);
			vertices.push_back(z);
			vertices.push_back(0.0f);
			vertices.push_back(1.0f);
			vertices.push_back(0.0f);

			for (int i = 0; i < 2; i++)
			{
				vertices.push_back(x + width);
				vertices.push_back(y);
				vertices.push_back(z + depth);
				vertices.push_back(0.0f);
				vertices.push_back(0.0f);
				vertices.push_back(1.0f);
			}

			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z + depth);
			vertices.push_back(0.0f);
			vertices.push_back(1.0f);
			vertices.push_back(0.0f);
		}

		if (depth == 0)
		{
			vertices.push_back(x);
			vertices.push_back(y + height);
			vertices.push_back(z);
			vertices.push_back(0.0f);
			vertices.push_back(1.0f);
			vertices.push_back(0.0f);

			for (int i = 0; i < 2; i++)
			{
				vertices.push_back(x + width);
				vertices.push_back(y + height);
				vertices.push_back(z);
				vertices.push_back(0.0f);
				vertices.push_back(0.0f);
				vertices.push_back(1.0f);
			}

			vertices.push_back(x + width);
			vertices.push_back(y);
			vertices.push_back(z);
			vertices.push_back(0.0f);
			vertices.push_back(1.0f);
			vertices.push_back(0.0f);
		}

		vertices.push_back(x);
		vertices.push_back(y);
		vertices.push_back(z);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		return vertices;
	}

void SnoopDogg::drawBody(GLFWwindow * window, GLuint * VAO)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Draw the triangle
	this->ourShader->Use();
	glBindVertexArray(*VAO);
	glDrawArrays(GL_TRIANGLES, 0, 11*6*2*6);
	glBindVertexArray(0);

	// Swap the screen buffers
	glfwSwapBuffers(window);
}

void SnoopDogg::drawHead()
{
}
