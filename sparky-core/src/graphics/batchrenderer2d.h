#pragma once

#include "renderer2d.h"
#include "buffers/indexBuffer.h"

namespace sparky {  namespace graphics {

<<<<<<< HEAD
#define RENDERER_MAX_SPRITES    10000
=======
#define RENDERER_MAX_SPRITES    60000
>>>>>>> adding bach renderer
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
<<<<<<< HEAD
=======
		VertexData* m_Buffer;
>>>>>>> adding bach renderer

	public:
		BatchRenderer2D();
		~BatchRenderer2D();
<<<<<<< HEAD
		void submit(const Rendrable2D* renderable) override;
=======
		void begin();
		void submit(const Rendrable2D* renderable) override;
		void end();
>>>>>>> adding bach renderer
		void flush() override;
	private:
		void init();
	};



}}