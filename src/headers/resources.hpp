#ifndef __RESOURCES_HPP__
#define __RESOURCES_HPP__

#include <map>
#include <string>

#include "shader.hpp"
class Resources
{
private:
	Resources() {}
public:
	static map<string, Shader> shaders;
	static Shader assign_shader(
		const char *vertex_shader_file,
		const char *fragment_shader_file,
		string key_shader
	);
	static Shader get_shader(string key_shader);
	// TODO: Texture Load
	static void clean();
};

#endif // __RESOURCES_HPP__