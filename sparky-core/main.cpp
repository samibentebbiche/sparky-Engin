
#include "src/graphics/window.h"
#include "src/utils/fileutils.h"
#include "src/graphics/shader.h"
#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexBuffer.h"
#include "src/graphics/buffers/vertexArray.h"
#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"

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

	// make the sprite
	Rendrable2D sprite(glm::vec3(5, 5, 0), glm::vec2(4, 4), glm::vec4(1, 0, 1, 1), shader);
	Rendrable2D sprite2(glm::vec3(7, 1, 0), glm::vec2(2, 3), glm::vec4(0.2f, 0, 1, 1), shader);
	Simple2DRenderer renderer;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (!window.closed())
	{
		window.processInput();

		float x, y = 0;
		window.getMoisePos(x, y);
		shader.setUniform2f("light_pos", glm::vec2( (float)( x * 16.0f / 800.0f) ,(float) (9.0f - y * 9.0f / 600.0f)));

		window.clear();

		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();
		window.update();
	}


	return 0;
}
