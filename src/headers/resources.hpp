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
	static std::map<std::string, Shader> shaders;
	
	static Shader assign_shader(
		const char *vertex_shader_file,
		const char *fragment_shader_file,
		string key_shader
	);
	static std::map<std::string, Shader> get_current_shaders();
	static void clean();
};

#endif // __RESOURCES_HPP__