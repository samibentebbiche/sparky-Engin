#pragma once

#include "glm/glm.hpp"
#include "buffers/buffer.h"
#include "buffers/indexBuffer.h"
#include "buffers/vertexArray.h"
#include "shader.h"

namespace sparky { namespace graphics {
	
	struct VertexData
	{
		glm::vec3 vertex;
		glm::vec4 color;
	};

	class Rendrable2D
	{
	protected:

		glm::vec3 m_Position;
		glm::vec2 m_Size;
		glm::vec4 m_Color;

		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
		Shader& m_Shader;

	public:
		Rendrable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color, Shader& shader)
			: m_Position(position), m_Color(color), m_Size(size), m_Shader(shader)
		{
			m_VertexArray = new VertexArray();

			GLfloat vertices[] =
			{
				0,				0,				0,
				0,				size.y,			0,
				size.x,			size.y,			0,
				size.x,			0,				0
			};
			GLfloat colors[] =
			{
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
			};

			m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
			m_IndexBuffer = new IndexBuffer(indices,6);
					
		}

		~Rendrable2D() 
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}

		inline Shader& getShader() const { return m_Shader; }

		inline const VertexArray* getVAO() const { return m_VertexArray; }
		inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
		
		inline const glm::vec3& getPosition() const { return m_Position; }
		inline const glm::vec2& getSize() const { return m_Size; }
		inline const glm::vec4& getColor() const { return m_Color; }

	};


}}