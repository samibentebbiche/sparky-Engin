#pragma once

#include "renderable2D.h"
namespace sparky {
namespace graphics {

	class Sprite : public Rendrable2D
	{
	private:

	public:
		Sprite(float x, float y, float width, float height, const glm::vec4& color);
	};



}}