#pragma once

#include "glm/glm.hpp"
#include <glad/glad.h>

#include "renderable2D.h"

namespace sparky { namespace  graphics {

	class Renderer2D
	{
	protected:
		std::vector<glm::mat4> m_TransformationStack;
		const glm::mat4* m_TransformationBack;
	protected:
		Renderer2D()
		{
			m_TransformationStack.push_back(glm::mat4(1));
			m_TransformationBack = &m_TransformationStack.back();
		}
	public:
		void push(const glm::mat4& matrix, bool override = false)
		{
			if(override)
				m_TransformationStack.push_back(matrix);
			else
				m_TransformationStack.push_back(m_TransformationStack.back() * matrix);

			m_TransformationBack = &m_TransformationStack.back();

		}
		void pop()
		{
			if(m_TransformationStack.size() > 1)
				m_TransformationStack.pop_back();

			m_TransformationBack = &m_TransformationStack.back();

			// TODO : Add log!
		}
		virtual void begin(){}
		virtual void submit(const Rendrable2D* renderable) = 0;
		virtual void end(){}
		virtual void flush() = 0;

	};




}}