#include "layer.h"

namespace sparky {
namespace graphics {

	Layer::Layer(Renderer2D* renderer, Shader* shader, glm::mat4 projectionmatrix)
		: m_Renderer(renderer), m_Shader(shader), m_ProjectionMatrix(projectionmatrix)
	{
		

		m_Shader->enable();
		m_Shader->setUniformMat4("projection",m_ProjectionMatrix);
		m_Shader->disable();
	}

	Layer::~Layer()
	{
		delete m_Shader;
		//delete m_Renderer;
		for (int i = 0; i < m_Renderables.size(); i++)
		{
			delete m_Renderables[i];
		}
	}

	void Layer::add(Rendrable2D* renderable)
	{
		m_Renderables.push_back(renderable);
	}

	void Layer::render() 
	{
		m_Shader->enable();
		m_Renderer->begin();
		for (const Rendrable2D* renderable : m_Renderables)
				renderable->submit(m_Renderer);

		m_Renderer->end();
		m_Renderer->flush();
	}
}
}