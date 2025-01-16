#pragma once

#include <glad/glad.h>
#include <iostream>
#include <vector>
#include "../utils/fileutils.h"
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>   


namespace sparky {	namespace graphics {


	class Shader
	{
	public: // make private
		GLuint m_ShaderID;
		const char* m_VertPath;
		const char* m_FragPath;
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();
		void setUniform1i(const char* name, const int v1);
		void setUniform1f(const char* name, const float v1);
		void setUniform2f(const char* name, const glm::vec2& vec);
		void setUniform3f(const char* name, const glm::vec3& vec);
		void setUniform4f(const char* name, const glm::vec4& vec);
		void setUniformMat4(const char* name, const glm::mat4& matrix);

		void enable() const;
		void disable() const;

	private:
		GLint getUniformLocation(const char* name);
		GLuint load();
	};

	unsigned int compileLog(GLuint shader);
}}