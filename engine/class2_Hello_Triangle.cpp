#include "hello_triangle.h"


float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};

const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource =
"#version 330 core                                        \n"
"out vec4 FragColor;                                      \n"
"void main(){\n"
"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); }   \n";


Class2_Hello_Triangle::Class2_Hello_Triangle()
{	
}

int Class2_Hello_Triangle:: class_main_process() {
	// first let's create the glfw window and rendering loop 
	if (!glfwInit()) {
		std::cout << "glfwInit failed!!\n";
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "hello triangle", NULL, NULL);
	// check the window 
	if (window == NULL) {
		std::cout << "window create failed!!\n";
		return -1;
	}
	glfwMakeContextCurrent(window);


	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW init failed!!" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);


	// let generate a vao  
	unsigned int VAO;
		// this function is aim to 
		// generate the VAO id and fill the parameter VAO  by it. 
	glGenVertexArrays(1, &VAO);
		// if you want to genrate many VAOs you can via the method below to fill the VAO
	/*unsigned int VAOs[10];
	glGenVertexArrays(10, VAOs);*/
		// bind the id
	glBindVertexArray(VAO);

	// create VBO and bind on the vao
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// create the shader source container and load the shader injecting the shader source into the shader container
	// create fragmentShader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// create vertexShader through the same way;
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// create a Shader program and link the vertexShader and fragmentShader
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
		// attach the two shader onto the shaderProgram
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	// rendering loop
	while (glfwWindowShouldClose(window) != true) {
		
		processInput(window);
		//rendering
		glClearColor(0.3f, 0.2f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
			// binding VAO
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//
		glfwSwapBuffers(window);
		glfwPollEvents();
		
	}

}

void Class2_Hello_Triangle::processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS ) {
		glfwSetWindowShouldClose(window, true);
	}
}

