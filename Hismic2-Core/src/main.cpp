#include "utils/Logger.h"
#include "BUILD.h"
#include <graphics/window.h>

int main(int argc,char *argv[]) {
	using namespace hismic;
	using namespace graphics;

	Utils::Logger logger;
	logger.PrintLog(FULL_VERSION_NAME, 1);

	Window window(NAME_VERSION,960,540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);

	while (!window.closed()) {
		
		window.clear();
		double x, y;
		window.getMousePosition(x,y);
		std::cout << x << "," << y << std::endl;
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