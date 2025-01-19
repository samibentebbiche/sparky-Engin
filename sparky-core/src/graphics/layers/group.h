#pragma once

#include "../renderable2D.h"

namespace sparky {
namespace graphics {

	class Group : public Rendrable2D
	{
	private:

		std::vector<Rendrable2D> m_Renderable;
		glm::mat4 m_TransformationMatrix;

	public:
		Group(); 
	};

}
}