#pragma once  //чтобы этот файл подгружался только один раз (если его где-то уже подгрузили)
#include <glad/glad.h>
#include <string>

namespace Renderer {
	class ShaderProgram {
	public:
		ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
		~ShaderProgram();
		bool isCompiled()const { return m_isCompiled; }
		void use() const;
		//запреты:
		ShaderProgram() = delete;
		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator=(const ShaderProgram&) = delete;
		ShaderProgram& operator=(ShaderProgram&&) noexcept;
		ShaderProgram(ShaderProgram&& shaderProgram) noexcept;
	private:
		bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID); // bool - произошла компил или нет
			               // /\код шейдера            /\тип шейдера            /\ индетификатор шейдера                                                                      
		
		bool m_isCompiled = false;
		GLuint m_ID = 0;
	};
}