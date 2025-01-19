#pragma once

#include "renderer2d.h"
#include <deque>
#include "static_sprite.h"
#include "renderable2D.h"

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