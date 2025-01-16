#include "shader.h"

namespace sparky {	namespace graphics {


		Shader::Shader(const char* vertPath, const char* fragPath) 
			: m_VertPath(vertPath), m_FragPath(fragPath)
		{
			m_ShaderID = load();
		}
		Shader::~Shader() 
		{
			glDeleteProgram(m_ShaderID);
		}

		GLint Shader::getUniformLocation(const char* name)
		{
			return glGetUniformLocation(m_ShaderID, name);
		}

		void Shader::setUniform1i(const char* name, const int v1)
		{
			GLint location = getUniformLocation(name);
			glUniform1i(location, v1);
		}

		void Shader::setUniform1f(const char* name, const float v1)
		{
			GLint location = getUniformLocation(name);
			glUniform1fv(location,1,&v1);
		}
		void Shader::setUniform2f(const char* name, const glm::vec2& vec)
		{
			GLint location = getUniformLocation(name);
			glUniform2f(location,vec.x, vec.y);
		}

		void Shader::setUniform3f(const char* name, const glm::vec3& vec)
		{
			GLint location = getUniformLocation(name);
			glUniform3f(location, vec.x, vec.y, vec.z);
		}

		void Shader::setUniform4f(const char* name, const glm::vec4& vec)
		{
			GLint location = getUniformLocation(name);
			glUniform4f(location, vec.x, vec.y, vec.z, vec.w);
		}

		void Shader::setUniformMat4(const char* name, const glm::mat4& matrix)
		{
			GLint location = getUniformLocation(name);
			glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));

		}
		void Shader::enable() const
		{
			glUseProgram(m_ShaderID);
		}

		void Shader::disable() const
		{
			glUseProgram(0);
		}

		GLuint Shader::load()
		{
			GLuint program = glCreateProgram();

			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
			

			std::string  vertSourceString = read_file(m_VertPath);
			std::string  fragSourceString = read_file(m_FragPath);

			const char* vertSource = vertSourceString.c_str();
			const char* fragSource = fragSourceString.c_str();
			
			glShaderSource(vertex, 1, &vertSource, NULL);
			glShaderSource(fragment, 1, &fragSource, NULL);

			glCompileShader(vertex);
			if (!compileLog(vertex)) return 0;
			glCompileShader(fragment);
			if (!compileLog(fragment)) return 0;

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		unsigned int compileLog(GLuint shader)
		{
			GLint result;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE)
			{
				GLint lenght;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &lenght);
				std::vector<char> error(lenght);

				glGetShaderInfoLog(shader, lenght, &lenght, &error[0]);
				std::cout << "Failed to compile shader : " << &error[0] << std::endl;
				glDeleteShader(shader);

				return 0;
			}
			return 1;
		}
}}