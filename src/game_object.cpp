#include "headers/game_object.hpp"

void GameObject::draw(Renderer &renderer)
{
	renderer.draw_texture(
		this->sprite,
		this->obj_position,
		this->obj_size,
		this->obj_rotation,
		this->obj_color
	);
}