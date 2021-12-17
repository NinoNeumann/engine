#define GLEW_STATIC
#pragma comment(lib,"glew32s.lib")
#include<iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	// Open GLFW Window
	GLFWwindow* window = glfwCreateWindow(800, 600, "hello", NULL, NULL);
	if (window == NULL) {
		std::cout << "´´½¨´°¿ÚÊ§°Ü£¡£¡\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// init GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "glew init fail!!\n";
		return -1;
	}
	
	glViewport(0, 0, 800, 600);

	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();

	return 0;
}
 