#include "utils/Logger.h"
#include "BUILD.h"
#include <graphics/window.h>
#include <maths/maths.h>
#include <graphics/shader.h>
#include <graphics/buffers/buffer.h>
#include <graphics/buffers/indexbuffer.h>
#include <graphics/buffers/vertexarray.h>

int main(int argc,char *argv[]) {
	using namespace hismic;
	using namespace graphics;
	using namespace maths;

	Utils::Logger logger;
	logger.PrintLog(FULL_VERSION_NAME, 1);

	Window window(NAME_VERSION,960,540);
	

#if 0
	GLfloat vertices[] = {
          0,0,0,
		  8,0,0,
		  0,3,0,
		  0,3,0,
		  8,3,0,
		  8,0,0
	};
	GLuint vbo;
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
#else
	GLfloat vertices[] = {
		  0,0,0,
		  0,3,0,
		  8,3,0,
		  8,0,0
	};
	GLushort indices[] = {
		0,1,2,
		2,3,0
	};


	VertexArray vao;
	Buffer* vbo = new Buffer(vertices,4*3,3);
	IndexBuffer ibo(indices, 6);

	vao.addBuffers(vbo, 0);


#endif
	mat4 ortho = mat4::orthographic(0.0f,16.0f,0.0f,9.0f,-1.0f,1.0f);
	
	Shader shader("src/shaders/basic.hvsh", "src/shaders/basic.hfsh");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4,3,0)));
	shader.setUniform2f("light_pos",vec2(4.0f,1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.closed()) {
		
		window.clear();
		double x, y;
		window.getMousePosition(x,y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f/960.0f), (float)(9.0f-y*9.0f/540.0f)));
#if 0
		glDrawArrays(GL_TRIANGLES, 0, 6);

#else 
		vao.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		shader.setUniformMat4("ml_matrix", mat4::translation(vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.bind();
		vao.unbind();
#endif
		window.update();
	}
	

	return 0;
}