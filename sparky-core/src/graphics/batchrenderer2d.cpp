
#include "batchrenderer2d.h"

namespace sparky {	namespace graphics {

	BatchRenderer2D::BatchRenderer2D()
	{
		init();
	}
	BatchRenderer2D::~BatchRenderer2D()
	{
		delete m_IBO;
		glDeleteBuffers(1, &m_VBO);
		
	}

	void BatchRenderer2D::init()
	{
		glGenVertexArrays(1, &m_VAO);
		glGenBuffers(1, &m_VBO);
		glBindVertexArray(m_VAO);

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE,NULL,GL_DYNAMIC_DRAW);
		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const void*)(offsetof(VertexData, VertexData::vertex)));
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE,(const void*) (offsetof(VertexData, VertexData::color)) );
		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		int offset = 0;
		GLushort indices[RENDERER_INDICES_SIZE];
		for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
		{
			indices[  i  ] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;

			offset += 4;
		}

		m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);


		glBindVertexArray(0);
	}


	void BatchRenderer2D::begin()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

		m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}
	void BatchRenderer2D::submit(const Rendrable2D* renderable)
	{


		const glm::vec3& position = renderable->getPosition();	

		const glm::vec2& size = renderable->getSize();
		const glm::vec4& color = renderable->getColor();
		

		int r = color.x * 255.0;
		int g = color.y * 255.0;
		int b = color.z * 255.0;
		int w = color.w * 255.0;

		unsigned int c = r << 24 | b << 16 | g << 8 | r;

		m_Buffer->vertex = glm::vec3(*m_TransformationBack * glm::vec4(position, 1.0f));
		m_Buffer->color = c;
		m_Buffer++;

		m_Buffer->vertex = glm::vec3(*m_TransformationBack *  glm::vec4(position.x, position.y + size.y, position.z, 1.0f));
		m_Buffer->color = c;
		m_Buffer++;

		m_Buffer->vertex = glm::vec3(*m_TransformationBack *  glm::vec4(position.x + size.x, position.y + size.y, position.z, 1.0f));
		m_Buffer->color = c;
		m_Buffer++;

		m_Buffer->vertex = glm::vec3(*m_TransformationBack *  glm::vec4(position.x + size.x, position.y, position.z, 1.0f));
		m_Buffer->color = c;
		m_Buffer++;

		m_IndexCount += 6;
	}

	void BatchRenderer2D::end()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}
	void BatchRenderer2D::flush()
	{
		glBindVertexArray(m_VAO);
		m_IBO->bind();

		glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, NULL);

		m_IBO->unbind();
		glBindVertexArray(0);

		m_IndexCount = 0;
	}

}}