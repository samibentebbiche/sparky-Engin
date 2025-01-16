#pragma once

#include "renderer2d.h"
#include <deque>

namespace sparky { namespace  graphics {

	class Simple2DRenderer : public Renderer2D
	{
	private:
		std::deque<const Rendrable2D*> m_RenderQueue;

	public:
		void submit(const Rendrable2D* renderable) override;
		void flush() override;


	};




}}