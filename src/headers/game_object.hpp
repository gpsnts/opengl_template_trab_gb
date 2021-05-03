#ifndef __GAME_OBJECT_HPP__
#define __GAME_OBJECT_HPP__

#include <string>

#include "pch/glad_pch.hpp"
#include "pch/glfw_pch.hpp"

#include <glm/glm.hpp>

#include "texture.hpp"
#include "renderer.hpp"

using namespace glm;

class GameObject
{
private: 
	vec2 obj_position, obj_size, obj_velocity;
  vec3 obj_color;
  GLfloat obj_rotation;
  GLboolean is_solid;
  GLboolean is_deleted;
  Texture sprite;
public:
	GameObject() :
	sprite() {
		this->obj_position 	= vec2(0.f, 0.f);
		this->obj_size 			=	vec2(1.f, 1.f);
		this->obj_velocity 	= vec2(0.f, 0.f);
		this->obj_color			= vec3(1.f, 1.f, 1.f);
		this->obj_rotation 	=	0.f;
		this->is_solid			=	false;
		this->is_deleted		=	false;
	};

	GameObject(
		Texture s_sprite,
		vec2 s_pos,
		vec2 s_size,
		vec3 s_color = vec3(1.f),
		vec2 s_velocity = vec2(0.f, 0.f)
	) 
	{
		this->obj_position 	= s_pos;
		this->obj_size			=	s_size;
		this->obj_velocity 	=	s_velocity;
		this->obj_color			=	s_color;
		this->obj_rotation	=	0.f;
		this->is_solid			=	false;
		this->is_deleted		=	false;
		this->sprite 				=	s_sprite;
	};

	virtual void draw(Renderer &renderer);
};

#endif // __GAME_OBJECT_HPP__