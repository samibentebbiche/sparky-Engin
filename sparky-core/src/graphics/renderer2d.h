#pragma once

#include "glm/glm.hpp"
#include <glad/glad.h>

#include "renderable2D.h"

namespace sparky { namespace  graphics {

	class Renderer2D
	{
	
	public:
		virtual void submit(const Rendrable2D* renderable) = 0;
		virtual void flush() = 0;


	};




}}