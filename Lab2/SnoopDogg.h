#pragma once

#define WIDTH 0.3f
#define GLEW_STATIC

#include <iostream>

// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// SOIL
#include <SOIL/SOIL.h>

// GLM
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

// Other includes
#include "shader.h"
#include <vector>

class SnoopDogg
{
public:
	SnoopDogg();
	~SnoopDogg();
	void drawSnoopDogg();
	void drawBody(GLFWwindow * window);
	void drawHead(GLFWwindow * window);
	void setTransform(glm::mat4 transform);

	/*
	body consists of 11 boxes, such as legs, hands, boots, arms, sax etc.
	36 vertices in each box, 6 coords in each vertice.
	Change access later
	*/
	GLfloat bodyVertices[11 * 36 * 6];
	//One box with 30 vertices (5 coords in each) - no face here
	GLfloat headVertices[5 * 6 * 5];
	//face vertices
	GLfloat faceVertices[6 * 5];
	//Textures
	GLuint faceTexture, hairTexture;

private:
	//this methods are used to draw whole Snoop. First 2 in constructor, other 2 in draw method
	void initBodyVertices();
	void initHeadVertices();
	void initTextures();
	void bindVertices();
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

	std::vector<GLfloat> getSquareVertices(GLfloat x, GLfloat y, GLfloat z,
		GLfloat width, GLfloat height, GLfloat depth, bool texture);

	
	Shader * ourShader;
	Shader * headShader;
	Shader * faceShader;
	GLuint VBO[3];
	GLuint VAO[3];
	glm::mat4 transform;

};

