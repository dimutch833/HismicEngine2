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

	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	Shader shader();

	while (!window.closed()) {
		
		window.clear();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}
	

	return 0;
}