
#include "src/graphics/window.h"
#include "src/utils/fileutils.h"
#include "src/graphics/shader.h"
#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexBuffer.h"
#include "src/graphics/buffers/vertexArray.h"
#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"

#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"

#include "src/graphics/batchrenderer2d.h"
#include "src/graphics/layers/tilelayer.h"
#include "src/graphics/layers/group.h"

#include "src/utils/time.h"
#include <time.h>



int main()
{
	using namespace sparky;
	using namespace graphics;

	// setup the window
	Window window("Sparky", 800, 600);
	Shader* shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader->enable();
	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	shader->setUniformMat4("projection", ortho);
	
	TileLayer layer(shader);
	//layer.add(new Sprite(0, 0, 2, 2, glm::vec4(0.8f, 0.2f, 0.8f, 1.0f)));
	

	srand(time(NULL));


	std::vector<Rendrable2D*> sprites;
	for (float y = -9.0f; y < 9.0f; y+= 0.2)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.2)
		{
			layer.add(new Sprite(x, y, 0.15f, 0.15f, glm::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}
	Shader* shader2 = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader2->enable();
	TileLayer layer2(shader2);
	layer2.add(new Sprite(-2.0f, -2.0f, 4.0f, 4.0f, glm::vec4(1.0f, 0.0f, 1.0f, 1.0f)));

	// make the sprite
	Sprite sprite(0, 0, 4, 4, glm::vec4(1, 0, 1, 1));
	Sprite sprite2(7, 7, 2, 3, glm::vec4(0.2f, 0, 1, 1));
	BatchRenderer2D renderer;

	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	while (!window.closed())
	{
		window.processInput();
		float x, y = 0;
		window.getMoisePos(x, y);
		shader->enable();
		shader->setUniform2f("light_pos", glm::vec2( (float)( x * 32.0f / 800.0f - 16.0f) ,(float) (9.0f - y * 18.0f / 600.0f)));
		shader2->enable();
		shader2->setUniform2f("light_pos", glm::vec2((float)(-1.0f, -1.0f)));

		window.clear();


		renderer.begin();

		for (int i = 0; i < sprites.size(); i++)
		{
			renderer.submit(sprites[i]);
		}


		renderer.end();

		renderer.flush();


		layer.render();
		layer2.render();
		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d Fps\n", frames);
			frames = 0;
		}

	}


	return 0;
}
