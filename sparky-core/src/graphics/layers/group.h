#pragma once

#include "../renderable2D.h"

namespace sparky {
namespace graphics {

	class Group : public Rendrable2D
	{
	private:

		std::vector<Rendrable2D*> m_Renderables;
		glm::mat4 m_TransformationMatrix;

	public:
		Group(const glm::mat4& transform); 
		void submit(Renderer2D* renderer) const override;
		void add(Rendrable2D* renderable);
	};

}
}