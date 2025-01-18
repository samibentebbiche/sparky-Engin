#pragma once

#include "renderer2d.h"
#include <deque>
#include "static_sprite.h"

namespace sparky { namespace  graphics {

	class Simple2DRenderer : public Renderer2D
	{
	private:

		std::deque<const StaticSprite*> m_RenderQueue;

	public:
		void submit(const Rendrable2D* renderable) override;
		void flush() override;


	};




}}