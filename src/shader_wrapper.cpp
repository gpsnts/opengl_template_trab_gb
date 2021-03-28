#include "headers/shader_wrapper.hpp"

#define USED_GL_ENUM(type) (type == GL_FRAGMENT_SHADER ? "GL_FRAGMENT_SHADER" : "GL_VERTEX_SHADER")

bool shader_compile(const char *file_name, GLuint *shader, GLenum type)
{
	FILE *file = fopen(file_name, "r");
	char *content;
	int compile_flag = -1;

	if (file != NULL)
	{
		fseek(file, 0, SEEK_END);
		size_t file_size = ftell(file);
		rewind(file);

		content = new char[file_size + 1];
		fread(content, sizeof(char), file_size, file);
		content[file_size] = '\0';

		fclose(file);

		// Shader creation
		*shader = glCreateShader(type);
		const GLchar *parsed_content = (const GLchar *)content;
		glShaderSource(*shader, 1, &parsed_content, NULL);
		glCompileShader(*shader);
		glGetShaderiv(*shader, GL_COMPILE_STATUS, &compile_flag);
		// End shader creation

		delete[] content, parsed_content;
	}

	if (GL_TRUE != compile_flag)
	{
		cerr << "ERROR COMPILING " << USED_GL_ENUM(type) << endl;
		return false;
	}
	return true;
}

bool create_program(GLuint *program, GLuint vertex_shader, GLuint fragment_shader)
{
	*program = glCreateProgram();
	glAttachShader(*program, vertex_shader);
	glAttachShader(*program, fragment_shader);
	
	glLinkProgram(*program);

	GLint compile_flag = -1;

	glGetProgramiv(*program, GL_LINK_STATUS, &compile_flag);

	if (GL_TRUE != compile_flag)
	{
		cerr << "ERROR CREATING/LINKING THE PROGRAM" << endl;
		return false;
	}

	glUseProgram(*program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	return true;
}