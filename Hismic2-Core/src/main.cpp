#include "utils/Logger.h"
#include "BUILD.h"
#include <graphics/window.h>
#include <maths/maths.h>
#include <graphics/shader.h>

int main(int argc,char *argv[]) {
	using namespace hismic;
	using namespace graphics;
	using namespace maths;

	Utils::Logger logger;
	logger.PrintLog(FULL_VERSION_NAME, 1);

	Window window(NAME_VERSION,960,540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


	GLfloat vertices[] = {
          -0.5f,-0.5f, 0.0f,
          -0.5f, 0.5f, 0.0f,
		   0.5f, 0.5f, 0.0f,
           0.5f, 0.5f, 0.0f,
		   0.5f,-0.5f, 0.0f,
		  -0.5f,-0.5f, 0.0f,
	};
	GLuint vbo;
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f,16.0f,0.0f,9.0f,-1.0f,1.0f);
	
	Shader shader("src/shaders/basic.hvsh", "src/shaders/basic.hfsh");
	shader.enable();
	glUniformMatrix4fv(glGetUniformLocation(shader.m_ShaderID,"pr_matrix"),1,GL_FALSE,ortho.elements);


	while (!window.closed()) {
		
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}
	

	return 0;
}