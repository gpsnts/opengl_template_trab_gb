#include "headers/utils.hpp"

bool shader_compile(const char *file_name, GLuint *shader, GLenum type)
{
	FILE *file = fopen(file_name, "r");

	if (file != NULL)
	{
		fseek(file, 0, SEEK_END);
		size_t file_size = ftell(file);
		rewind(file);

		char *content = new char[file_size];

		fread(content, sizeof(char), file_size, file);

		fclose(file);

		printf("file %s\nCONTENT:\n\n%s", file_name, content);

		return shader_assign(content, shader, type);
	}

	return false;
}

bool shader_assign(char* shader_content, GLuint *shader, GLenum type)
{
	*shader = glCreateShader(GL_FRAGMENT_SHADER);

	const GLchar* parsed_content = (const GLchar*) shader_content;

	glShaderSource(*shader, 1, &parsed_content, NULL);

	glCompileShader(*shader);

	int compile_flag = -1;

	glGetShaderiv(*shader, GL_COMPILE_STATUS, &compile_flag);

	if (GL_TRUE != compile_flag) return false;
	return true;
}

bool create_program(GLuint frag_shader, GLuint vert_shader, GLuint *program)
{
	glAttachShader(*program, frag_shader);
	glAttachShader(*program, vert_shader);

	glLinkProgram(*program);

	GLint compile_flag = -1;

	glGetProgramiv(*program, GL_LINK_STATUS, &compile_flag);

	if (GL_TRUE != compile_flag) return false;

	glDeleteShader(frag_shader);
  glDeleteShader(vert_shader);
	return true;
}
