#include "group.h"

namespace sparky {
namespace graphics {

	Group::Group(const glm::mat4& transform)
		: m_TransformationMatrix(transform)
	{
	}

	void Group::submit(Renderer2D* renderer) const
	{
		renderer->push(m_TransformationMatrix);
		for (const Rendrable2D* renderable : m_Renderables)
		{
			renderable->submit(renderer);
		}
		renderer->pop();
	}

	void Group::add(Rendrable2D* renderable)
	{
		m_Renderables.push_back(renderable);
	}


}
}