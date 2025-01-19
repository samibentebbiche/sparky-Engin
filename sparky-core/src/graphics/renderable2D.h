#pragma once

#include "glm/glm.hpp"
#include "buffers/buffer.h"
#include "buffers/indexBuffer.h"
#include "buffers/vertexArray.h"
#include "shader.h"

#include "renderer2d.h"
namespace sparky { namespace graphics {
	
	struct VertexData
	{
		glm::vec3 vertex;
		//glm::vec4 color;
		unsigned int color;
	};

	class Rendrable2D
	{
	protected:

		glm::vec3 m_Position;
		glm::vec2 m_Size;
		glm::vec4 m_Color;
	protected:
		Rendrable2D() { }
	public:
		Rendrable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color)
			: m_Position(position), m_Color(color), m_Size(size)
		{ }

		~Rendrable2D() 
		{ }
		
		virtual void submit(Renderer2D* renderer) const
		{
			renderer->submit(this);
		}

		inline const glm::vec3& getPosition() const { return m_Position; }
		inline const glm::vec2& getSize() const { return m_Size; }
		inline const glm::vec4& getColor() const { return m_Color; }

	};


}}