#include "utils/Logger.h"
#include "BUILD.h"
#include <graphics/window.h>
#include <maths/maths.h>
#include <graphics/shader.h>

#include <graphics/buffers/buffer.h>
#include <graphics/buffers/indexbuffer.h>
#include <graphics/buffers/vertexarray.h>

#include <graphics/simple2drenderer.h>
#include <graphics/BatchRenderer2D.h>
#include <graphics/renderer2d.h>

#include <graphics/static_sprite.h>
#include <graphics/sprite.h>

#include <utils/timer.h>
#include <time.h>

#define BATCH_RENDERER 1

int main(int argc,char *argv[]) {
	using namespace hismic;
	using namespace graphics;
	using namespace maths;

	Utils::Logger logger;
	logger.PrintLog(FULL_VERSION_NAME, 1);

	Window window(NAME_VERSION,960,540);
	mat4 ortho = mat4::orthographic(0.0f,16.0f,0.0f,9.0f,-1.0f,1.0f);
	
	Shader shader("src/shaders/basic.hvsh", "src/shaders/basic.hfsh");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);



	std::vector<Renderable2D*> sprites;

	srand(time(NULL));
	

	for (float y = 0; y < 9.0f; y+= 0.05) {
		for (float x = 0; x < 16.0f; x+= 0.05) {
			sprites.push_back(new 
#if BATCH_RENDERER
				Sprite
#else
				StaticSprite
#endif
				(x,y,0.9f,0.9f,maths::vec4(rand() % 1000 / 1000.0f,0,1,1)
#if !BATCH_RENDERER
					,shader
#endif					
					));
		}
	}

#if BATCH_RENDERER
	Sprite sprite(5,5,4,4, maths::vec4(1, 0, 1, 1));
	Sprite sprite2(7,1,2,3, maths::vec4(0.2f, 0, 1, 1));
	BatchRenderer2D  renderer;

#else
	StaticSprite sprite(5, 5, 4, 4, maths::vec4(1, 0, 1, 1),shader);
	StaticSprite sprite2(7, 1, 2, 3, maths::vec4(0.2f, 0, 1, 1),shader);
	Simple2DRenderer  renderer;
#endif

	shader.setUniform2f("light_pos",vec2(4.0f,1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed()) {
		window.clear();
		double x, y;
		window.getMousePosition(x,y);
		
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
#if BATCH_RENDERER
		renderer.begin();
#endif
		for (int i = 0; i < sprites.size(); i++) {
			renderer.submit(sprites[i]);
		}
#if BATCH_RENDERER
		renderer.end();
#endif
		renderer.flush();

		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			logger.PrintLog(std::to_string(frames).c_str(),1);
			frames = 0;
		}
		
	}
	

	return 0;
}