#pragma once

#include "renderable2D.h"
namespace sparky {
namespace graphics {

	class StaticSprite : public Rendrable2D
	{
	private:
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
		Shader& m_Shader;

	public:
		StaticSprite(float x, float y, float width, float height, const glm::vec4& color, Shader& shader);
		~StaticSprite();


		inline Shader& getShader() const { return m_Shader; }

		inline const VertexArray* getVAO() const { return m_VertexArray; }
		inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
	};



}
}