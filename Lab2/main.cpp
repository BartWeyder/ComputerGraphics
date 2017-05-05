#include "SnoopDogg.h"

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint Width = 800, HEIGHT = 600;

static GLfloat rotationSpeed = 50.0f;
static glm::vec3 axis = glm::vec3(0.0f, 1.0f, 0.0f);

// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(Width, HEIGHT, "MeetSnoop", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, Width, HEIGHT);

	glEnable(GL_DEPTH_TEST);

	SnoopDogg * snoopDogg = new SnoopDogg();

	

	
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 transform;
		transform = glm::rotate(transform, (GLfloat)glfwGetTime() * rotationSpeed, axis);//glm::vec3(0.0f, 1.0f, 0.0f));
		snoopDogg->setTransform(transform);

		snoopDogg->drawHead(window);
		snoopDogg->drawBody(window);
		
		// Swap the screen buffers
		glfwSwapBuffers(window);

	}

	glfwTerminate();
	return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	int randomX, randomY, randomZ;
	if (action == GLFW_PRESS)
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;
		case GLFW_KEY_UP:
			rotationSpeed += 10;
			break;
		case GLFW_KEY_DOWN:
			if (rotationSpeed >= 10.0f)
				rotationSpeed -= 10.0f;
			else
				rotationSpeed = 0.0f;
			break;
		case GLFW_KEY_SPACE:
			if (rotationSpeed == 0)
				rotationSpeed = 50.0f;
			else
				rotationSpeed = 0.0f;
			break;
		case GLFW_KEY_A:
			randomX = -100 + rand() % 200;
			randomY = -100 + rand() % 200;
			randomZ = -100 + rand() % 200;
			axis.x = randomX / 100.0f;
			axis.y = randomY / 100.0f;
			axis.z = randomZ / 100.0f;
			break;
		default:
			break;
		}
}