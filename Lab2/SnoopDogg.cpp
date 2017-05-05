#include "SnoopDogg.h"

SnoopDogg::SnoopDogg()
{
	//init shaders
	ourShader = new Shader("SnoopDogg.vs", "SnoopDogg.frag");
	headShader = new Shader("HeadShader.vs", "HeadShader.frag");
	faceShader = new Shader("FaceShader.vs", "FaceShader.frag");
	//init vertices
	initBodyVertices();
	initHeadVertices();
	//bind vertices
	bindVertices();
	//init textures
	initTextures();
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
void SnoopDogg::initBodyVertices()
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
		110 / 255.0f, 62 / 255.0f, 42 / 255.0f, false);
	vertices.insert(vertices.begin(), boxVertices.begin(), boxVertices.end());
	boxVertices = this->getBoxVertices(0.65f, 0.4f, -WIDTH / 2, 0.1f, 0.1f, WIDTH,
		110 / 255.0f, 62 / 255.0f, 42 / 255.0f, false);
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

/*
Generates head vertices into headVertices array.
*/
void SnoopDogg::initHeadVertices()
{
	std::vector<GLfloat> vertices, square;
	square = this->getSquareVertices(-0.125f, 0.5f, -WIDTH / 2, 0.25f, 0.3f, 0, true);
	vertices.insert(vertices.end(), square.begin(), square.end());
	square = this->getSquareVertices(-0.125f, 0.5f, -WIDTH / 2, 0.25f, 0, WIDTH, true);
	vertices.insert(vertices.end(), square.begin(), square.end());
	square = this->getSquareVertices(-0.125f, 0.5f, -WIDTH / 2, 0, 0.3f, WIDTH, true);
	vertices.insert(vertices.end(), square.begin(), square.end());
	//square = this->getSquareVertices(0.125f, 0.8f, WIDTH / 2, -0.25f, -0.3f, 0, true);
	//vertices.insert(vertices.end(), square.begin(), square.end());
	square = this->getSquareVertices(0.125f, 0.8f, WIDTH / 2, -0.25f, 0, -WIDTH, true);
	vertices.insert(vertices.end(), square.begin(), square.end());
	square = this->getSquareVertices(0.125f, 0.8f, WIDTH / 2, 0, -0.3f, -WIDTH, true);
	vertices.insert(vertices.end(), square.begin(), square.end());
	//copy into array
	std::copy(vertices.begin(), vertices.end(), this->headVertices);

	square = this->getSquareVertices(-0.125f, 0.5f, WIDTH / 2, 0.25f, 0.3f, 0, true);
	//copy face into array
	std::copy(square.begin(), square.end(), this->faceVertices);
	//in this method i will leave vectors with data, because I don't know is it necessary to clean memory
}

void SnoopDogg::initTextures()
{
	//1st texture
	glGenTextures(1, &this->hairTexture);
	glBindTexture(GL_TEXTURE_2D, this->hairTexture);
	//wrapping params
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//filter params
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//loading image
	int texWidth, texHeight;
	unsigned char * image = SOIL_load_image("hair.jpg", &texWidth, &texHeight, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	//2nd texture
	glGenTextures(1, &this->faceTexture);
	glBindTexture(GL_TEXTURE_2D, this->faceTexture);
	//wrapping params
	float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	//filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//loading new image
	image = SOIL_load_image("snoop.jpg", &texWidth, &texHeight, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void SnoopDogg::bindVertices()
{
	glGenVertexArrays(3, this->VAO);
	glGenBuffers(3, this->VBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(this->VAO[0]);

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->bodyVertices), this->bodyVertices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0); // Unbind VAO

	//head
	glBindVertexArray(this->VAO[1]);

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->headVertices), this->headVertices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Texture attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	//face
	glBindVertexArray(this->VAO[2]);

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->faceVertices), this->faceVertices, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Texture attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
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

/*
Generates vertices for square with texture vertices.
*/
std::vector<GLfloat> SnoopDogg::getSquareVertices(GLfloat x, GLfloat y, GLfloat z, 
	GLfloat width, GLfloat height, GLfloat depth, bool texture)
{
	if (!texture)
	{
		return std::vector<GLfloat>();
	}
	std::vector<GLfloat> vertices;
	vertices.push_back(x);
	vertices.push_back(y);
	vertices.push_back(z);
	vertices.push_back(0.0f);
	vertices.push_back(0.0f);

	if (width == 0)
	{
		vertices.push_back(x);
		vertices.push_back(y + height);
		vertices.push_back(z);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);

		for (int i = 0; i < 2; i++)
		{
			vertices.push_back(x);
			vertices.push_back(y + height);
			vertices.push_back(z + depth);
			vertices.push_back(1.0f);
			vertices.push_back(1.0f);
		}

		vertices.push_back(x);
		vertices.push_back(y);
		vertices.push_back(z + depth);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);
	}

	if (height == 0)
	{
		vertices.push_back(x + width);
		vertices.push_back(y);
		vertices.push_back(z);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);

		for (int i = 0; i < 2; i++)
		{
			vertices.push_back(x + width);
			vertices.push_back(y);
			vertices.push_back(z + depth);
			vertices.push_back(1.0f);
			vertices.push_back(1.0f);
		}

		vertices.push_back(x);
		vertices.push_back(y);
		vertices.push_back(z + depth);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);
	}

	if (depth == 0)
	{
		vertices.push_back(x);
		vertices.push_back(y + height);
		vertices.push_back(z);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);

		for (int i = 0; i < 2; i++)
		{
			vertices.push_back(x + width);
			vertices.push_back(y + height);
			vertices.push_back(z);
			vertices.push_back(1.0f);
			vertices.push_back(1.0f);

		}

		vertices.push_back(x + width);
		vertices.push_back(y);
		vertices.push_back(z);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);

	}

	vertices.push_back(x);
	vertices.push_back(y);
	vertices.push_back(z);
	vertices.push_back(0.0f);
	vertices.push_back(0.0f); 
	return vertices;
}

void SnoopDogg::drawBody(GLFWwindow * window)
{
	// Draw the triangle
	this->ourShader->Use();
	GLint transformLoc = glGetUniformLocation(this->ourShader->Program, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

	glBindVertexArray(this->VAO[0]);
	glDrawArrays(GL_TRIANGLES, 0, 11 * 6 * 2 * 6);
	glBindVertexArray(0);
}

void SnoopDogg::drawHead(GLFWwindow * window)
{
	glActiveTexture(GL_TEXTURE0);

	GLint headLocation = glGetUniformLocation(this->headShader->Program, "ourTexture");
	
	glBindTexture(GL_TEXTURE_2D, this->hairTexture);
	glUniform1i(headLocation, 0);
	
	this->headShader->Use();

	GLint transformLoc = glGetUniformLocation(this->headShader->Program, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	glBindVertexArray(this->VAO[1]);
	glDrawArrays(GL_TRIANGLES, 0, 5 * 6 * 5);
	glBindVertexArray(0); 
	
	GLint faceLocation = glGetUniformLocation(this->faceShader->Program, "ourTexture");
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->faceTexture);
	glUniform1i(faceLocation, 0);

	this->faceShader->Use();
	
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	glBindVertexArray(this->VAO[2]);
	glDrawArrays(GL_TRIANGLES, 0, 6 * 5);
	glBindVertexArray(0);
	
}

void SnoopDogg::setTransform(glm::mat4 transform)
{
	this->transform = transform;
}
