#pragma once

#define WIDTH 0.3f
#define GLEW_STATIC

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <SOIL\SOIL.h>
#include "shader.h"
#include <vector>

class SnoopDogg
{
public:
	SnoopDogg();
	~SnoopDogg();
	void drawSnoopDogg();
	void drawBody(GLFWwindow * window, GLuint * VAO);

	//body consists of 11 boxes, such as legs, hands, boots, arms, sax etc. Change access later
	GLfloat bodyVertices[(11 * 36 * 6)];
private:
	//this methods are used to draw whole Snoop. First 2 in constructor, other 2 in draw method
	void initBody();
	void initHead();
	//gens box vertices
	std::vector<GLfloat> getBoxVertices(GLfloat x, GLfloat y, GLfloat z,
		GLfloat width, GLfloat height, GLfloat depth,
		GLfloat colorX, GLfloat colorY, GLfloat colorZ, bool toxic);

	//gens squares vertices for boxes
	std::vector<GLfloat> getSquareVertices(GLfloat x, GLfloat y, GLfloat z,
		GLfloat width, GLfloat height, GLfloat depth,
		GLfloat colorX, GLfloat colorY, GLfloat colorZ);

	//gens toxic squares
	std::vector<GLfloat> getSquareVertices(GLfloat x, GLfloat y, GLfloat z,
		GLfloat width, GLfloat height, GLfloat depth);
	
	void drawHead();

	
	Shader * ourShader;
};

