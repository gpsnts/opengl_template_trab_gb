#ifndef __RESOURCES_HPP__
#define __RESOURCES_HPP__

#include <map>
#include <string>

#include "stb_image.h"

#include "texture.hpp"
#include "shader.hpp"

class Resources
{
private:
	Resources() {}
	static Texture load_texture_file(
		string const &file,
		GLboolean alpha
	);
public:
	static map<string, Shader> 	shaders;
	static map<string, Texture> textures;

	static Shader assign_shader(
		const char *vertex_shader_file,
		const char *fragment_shader_file,
		string key_shader
	);

	static Texture assign_texture(
		const char *texture_file,
		GLboolean alpha,
		string key_texture
	);

	static Shader 	get_shader(string key_shader);
	static Texture 	get_texture(string key_texture);

	static void clean();
};

#endif // __RESOURCES_HPP__