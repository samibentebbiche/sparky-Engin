#pragma once

#include "../renderable2D.h"
#include "../renderer2d.h"

namespace sparky {
namespace graphics {

	class Layer
	{
	protected:

		Renderer2D* m_Renderer;
		std::vector<Rendrable2D*> m_Renderables;
		Shader* m_Shader;

		glm::mat4 m_ProjectionMatrix;

	protected:
		Layer(Renderer2D* renderer, Shader* shader, glm::mat4 projectionmatrix);

	public:
		virtual ~Layer();

		virtual void add(Rendrable2D* renderabl);
		virtual void render();

	};

}
}