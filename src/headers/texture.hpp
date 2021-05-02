#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include "pch/glad_pch.hpp"
#include "pch/glfw_pch.hpp"

class Texture
{
private:
 	GLuint width, height;
 	GLuint wrap_s, wrap_t;
 	GLuint internal_format, image_format;
 	GLuint filter_min, filter_max;
public:
	GLuint texture_id;

  Texture()
	{
		this->width = 0; this->height	= 0;
		this->internal_format 				= GL_RGB;
		this->image_format 						= GL_RGB;
		this->wrap_s 									= GL_REPEAT;
		this->wrap_t 									= GL_REPEAT;
		this->filter_min 							= GL_LINEAR;
		this->filter_max 							= GL_LINEAR;
		glGenTextures(1, &this->texture_id);
	};

	void set_internal_format(GLuint s_internal_format)
	{
		this->internal_format = s_internal_format;
	}

	void set_image_format(GLuint s_image_format)
	{
		this->internal_format = s_image_format;
	}

  void generate(GLuint width, GLuint height, unsigned char* data);
  void bind() const;
};

#endif // __TEXTURE_HPP__