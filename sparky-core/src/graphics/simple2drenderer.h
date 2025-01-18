#pragma once

#include "renderer2d.h"
#include <deque>
<<<<<<< HEAD
=======
#include "static_sprite.h"
>>>>>>> adding bach renderer

namespace sparky { namespace  graphics {

	class Simple2DRenderer : public Renderer2D
	{
	private:
<<<<<<< HEAD
		std::deque<const Rendrable2D*> m_RenderQueue;
=======
		std::deque<const StaticSprite*> m_RenderQueue;
>>>>>>> adding bach renderer

	public:
		void submit(const Rendrable2D* renderable) override;
		void flush() override;


	};




}}