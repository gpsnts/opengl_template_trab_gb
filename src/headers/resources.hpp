#ifndef __RESOURCES_HPP__
#define __RESOURCES_HPP__

#include <map>
#include <string>

#include "shader.hpp"

class Resources
{
private:
	// Disable default constructor (static class)
	Resources() {}
public:
	// Map all created shaders
	static std::map<std::string, Shader> shaders;
	
	/** Function */
	// Assing shader creation (vertex, fragment)
	static Shader assign_shader(const char *vertex_shader_file, const char *fragment_shader_file, string key);

	static std::map<std::string, Shader> get_current_shaders();

	static void clean();
};

#endif // __RESOURCES_HPP__