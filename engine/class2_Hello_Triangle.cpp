#define GLEW_STATIC
#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>


class Class2_Hello_Triangle {
public:
	Class2_Hello_Triangle();
	void processInput(GLFWwindow*);
	int class_main_process();

};


Class2_Hello_Triangle::Class2_Hello_Triangle()
{
}

int class_main_process() {
	// first let's create the glfw window and rendering loop 
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "hello triangle", NULL, NULL);
	// check the window 
	if (window == NULL) {
		std::cout << "window create failed!!\n";
		return -1;
	}


	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW init failed!!" << std::endl;
		return -1;
	}

	// rendering loop
	while (glfwWindowShouldClose(window) != true) {
		
		processInput(window);
		//rendering

		//
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS ) {
		glfwSetWindowShouldClose(window, true);
	}
}

