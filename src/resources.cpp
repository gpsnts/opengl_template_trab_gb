#include "headers/resources.hpp"

// Instance (because it's a static)
std::map<std::string, Shader>	Resources::shaders;

Shader Resources::assign_shader(
	const char *vertex_shader_file,
	const char *fragment_shader_file,
	string key
)
{
	Shader _shader;
	_shader.compile(vertex_shader_file, fragment_shader_file);
	shaders[key] = _shader;

	return shaders[key];
}

// Runnable after deleting VAO(s)/VBO(s)
void Resources::clean()
{
	for (auto iter_shaders : shaders)
	{
		glDeleteProgram(iter_shaders.second.getProgram());
	}
}

std::map<std::string, Shader> Resources::get_current_shaders()
{
	return shaders;
}