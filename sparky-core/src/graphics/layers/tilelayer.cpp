#include "tilelayer.h"
#include "../batchrenderer2d.h"

namespace sparky {
namespace graphics {

	TileLayer::TileLayer(Shader* shader)
		: Layer(new BatchRenderer2D(), shader,glm::ortho(-16.0f, 16.0f, -9.0f, 9.0f))
	{
	}

	TileLayer::~TileLayer()
	{
	}

}
}