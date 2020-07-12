#include "utils/Logger.h"
#include "BUILD.h"
#include <graphics/window.h>
#include <maths/maths.h>
#include <utils/fileutils.h>

int main(int argc,char *argv[]) {
	using namespace hismic;
	using namespace graphics;
	using namespace maths;

	std::string file = read_file("main.cpp");
	std::cout << file << std::endl;

	Utils::Logger logger;
	logger.PrintLog(FULL_VERSION_NAME, 1);

	Window window(NAME_VERSION,960,540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);

	vec4 a(1.0f,2.0f,5.0f,0.5);
	vec4 b(0.2f, 0.3f, 0.8f, 1.0f);


	mat4 position = mat4::translation(vec3(2,3,4));
	position *= mat4::identity();
	vec4 c = position.columns[3];
	std::cout << c << std::endl;

	while (!window.closed()) {
		
		window.clear();

#if 1 	
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#else 
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}
	

	return 0;
}