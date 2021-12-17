#define GLEW_STATIC

#include<iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>




void processInput(GLFWwindow*);

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
	// pay attention!! the glew lib must be x64 and please check your debug version(be x64 too) before you start and debug!!
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "glew init fail!!\n";
		return -1;
	}
	
	glViewport(0, 0, 800, 600);


	// this is rendering loop
	while (!glfwWindowShouldClose(window)) {


		// next we want to let the window we create, to detect the key we pressed and process something like close the window
		processInput(window);

		// in the section below we can process the buffer behind and use Swap Buffer to let the buffer behind to the fornt
		// section process start
		// let refresh the window   
		// you can think it in that way: glclearcolor set what we want the color is and glclear set the picture color according to the glclearColor()
		glClearColor(1, 0, 0, 0.0f);  // its set the behind buffer
		glClear(GL_COLOR_BUFFER_BIT);
		// so we can put some function in this section using

		// section process end
		glfwPollEvents();
		glfwSwapBuffers(window);
		
	}
	glfwTerminate();


	return 0;
}


void processInput(GLFWwindow* window) {
	// this if sentence aim to judge wheather we pressed the escape key  
	// and if we press the key  the window should be closed.
	// and here is two method to close the window  do they have any differences?
	//     note : the function:  glfwWindowShouldClose(window); have no use!!!!  
	//			i know glfwWindowShouldClose(window) is to check wheather the window should be closed
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		
		glfwSetWindowShouldClose(window, true);
		return;
	}
}
 