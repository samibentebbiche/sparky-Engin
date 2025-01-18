
#include "src/graphics/window.h"
#include "src/utils/fileutils.h"
#include "src/graphics/shader.h"
#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexBuffer.h"
#include "src/graphics/buffers/vertexArray.h"
#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"
<<<<<<< HEAD
=======
#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"

#include "src/graphics/batchrenderer2d.h"
#include "src/utils/time.h"
#include <time.h>

#define BATCH_RENDERER 1

>>>>>>> adding bach renderer

int main()
{
	using namespace sparky;
	using namespace graphics;

	// setup the window
	Window window("Sparky", 800, 600);
	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	shader.setUniformMat4("projection", ortho);
<<<<<<< HEAD

	// make the sprite
	Rendrable2D sprite(glm::vec3(5, 5, 0), glm::vec2(4, 4), glm::vec4(1, 0, 1, 1), shader);
	Rendrable2D sprite2(glm::vec3(7, 1, 0), glm::vec2(2, 3), glm::vec4(0.2f, 0, 1, 1), shader);
	Simple2DRenderer renderer;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (!window.closed())
	{
		window.processInput();

=======
	
	srand(time(NULL));

#if BATCH_RENDERER
#define SPRITE_TYPE Sprite
#define SHADER_ARG 
#else
#define SPRITE_TYPE StaticSprite
#define SHADER_ARG , shader
#endif

	std::vector<Rendrable2D*> sprites;
	for (float y = 0; y < 9.0f; y+= 0.1)
	{
		for (float x = 0; x < 16.0f; x += 0.1)
		{
			sprites.push_back(new SPRITE_TYPE(x, y, 0.08f, 0.08f, glm::vec4(rand() % 1000 / 1000.0f, 0, 1, 1) SHADER_ARG));
		}
	}
#if BATCH_RENDERER
	// make the sprite
	Sprite sprite(0, 0, 4, 4, glm::vec4(1, 0, 1, 1));
	Sprite sprite2(7, 7, 2, 3, glm::vec4(0.2f, 0, 1, 1));
	BatchRenderer2D renderer;


#else
	// make the sprite
	StaticSprite sprite(0, 0, 4, 4, glm::vec4(1, 0, 1, 1), shader);
	StaticSprite sprite2(7, 7, 2, 3, glm::vec4(0.2f, 0, 1, 1), shader);
	Simple2DRenderer renderer;
#endif
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	while (!window.closed())
	{
		window.processInput();
>>>>>>> adding bach renderer
		float x, y = 0;
		window.getMoisePos(x, y);
		shader.setUniform2f("light_pos", glm::vec2( (float)( x * 16.0f / 800.0f) ,(float) (9.0f - y * 9.0f / 600.0f)));

		window.clear();
<<<<<<< HEAD

		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();
		window.update();
=======
#if BATCH_RENDERER
		renderer.begin();
#endif
		for (int i = 0; i < sprites.size(); i++)
		{
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
			printf("%d Fps\n", frames);
			frames = 0;
		}

>>>>>>> adding bach renderer
	}


	return 0;
}
