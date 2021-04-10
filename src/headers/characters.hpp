#ifndef __CHARACTERS_HPP__
#define __CHARACTERS_HPP__

#include <map>
#include <string>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "pch/glfw_pch.hpp"
#include "pch/glad_pch.hpp"
#include "resources.hpp"

using namespace glm;

struct Character {
	GLuint 	TextureID;
	ivec2 	Size;
	ivec2 	Bearing;
	GLuint 	Advance;
};

class Characters
{
private:
	FT_Library ft;
	FT_Face face;
	std::map<GLchar, Character> characters;
	mat4 projection;
public:
	Characters()
	{
		if (FT_Init_FreeType(&ft)) std::cout << "ERROR - init FreeType" << std::endl;
		if (FT_New_Face(ft, "../src/fonts/CozetteVector.ttf", 0, &face)) std::cout << "ERROR - load font" << std::endl;

		FT_Set_Pixel_Sizes(face, 0, 48);
		std::cout << "Loaded - CozetteVector.ttf" << std::endl;	
	}
	
	Characters(const char *file_path)
	{
		if (FT_Init_FreeType(&ft)) std::cout << "ERROR - init FreeType" << std::endl;
		if (FT_New_Face(ft, file_path, 0, &face)) std::cout << "ERROR - load font" << std::endl;

		FT_Set_Pixel_Sizes(face, 0, 48);
		std::cout << "Loaded - Font" << std::endl;	
	}
};

#endif // __CHARACTERS_HPP__