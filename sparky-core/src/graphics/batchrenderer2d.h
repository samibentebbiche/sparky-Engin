#pragma once

#include "renderer2d.h"
#include "buffers/indexBuffer.h"
#include "renderable2D.h"
namespace sparky {  namespace graphics {


#define RENDERER_MAX_SPRITES    60000
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX  0
#define SHADER_COLOR_INDEX   1

	class BatchRenderer2D : public Renderer2D
	{

	private:
		GLuint m_VAO;
		IndexBuffer* m_IBO;
		GLsizei m_IndexCount;
		GLuint m_VBO;

		VertexData* m_Buffer;

	public:
		BatchRenderer2D();
		~BatchRenderer2D();
		void begin() override;
		void submit(const Rendrable2D* renderable) override;
		void end() override;
		void flush() override;
	private:
		void init();
	};



}}