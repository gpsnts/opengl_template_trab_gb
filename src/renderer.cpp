#include "headers/renderer.hpp"

std::map<std::string, GLuint> Renderer::get_vaos()
{
	return vaos;
}

std::map<std::string, GLuint> Renderer::get_vbos()
{
	return vbos;
}

std::map<std::string, GLuint> Renderer::get_uniforms_indexes()
{
	return uniforms_indexes;
}