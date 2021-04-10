#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#define GL_CALC_STRIDE(x) (x * sizeof(GLfloat))
#define GL_CALC_OFFSET(x) ((GLvoid *)(x * sizeof(GLfloat)))

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <initializer_list> // "inline array"

#include "pch/glfw_pch.hpp"

#include <iostream>
using namespace std;

enum Type {
	DATA,
	POSITION,
	COLOR,
	INDEXES
};

class Renderer
{
private:
	std::map<std::string, GLuint> vaos;
	std::map<std::string, GLuint> vbos;
	std::map<std::string, GLuint> ebos;

	std::map<std::string, std::vector<GLuint>> ebos_indexes;
	std::map<std::string, std::vector<GLfloat>> data;
	std::map<std::string, std::vector<GLfloat>> positions;
	std::map<std::string, std::vector<GLfloat>> colors;
public:
	Renderer() 
	: vaos(), vbos(), ebos(),
		ebos_indexes(), data(), positions(), colors() {};

	std::map<std::string, GLuint> get_vaos();
	std::map<std::string, GLuint> get_vbos();
	std::map<std::string, GLuint> get_ebos();

	std::map<std::string, std::vector<GLuint>> get_ebos_indexes();
	std::map<std::string, std::vector<GLfloat>> get_data();
	std::map<std::string, std::vector<GLfloat>> get_positions();
	std::map<std::string, std::vector<GLfloat>> get_colors();

	void set_data(
		Type selected,
		string key_selected,
		std::initializer_list<GLfloat> payload
	);

	void set_ebo_data(
		string key_selected,
		std::initializer_list<GLuint> payload
	);

	void bind_buffer(
		Type type,
		string key_buffer,
		string key_array
	);

	void bind_ebo_buffer(
		string key_ebo_buffer,
		string key_array
	);

	void bind_vertex(string key_vertex);

	void vbo_attrib(
		string key_buffer,
		GLuint layout_index,
		int stride,
		int offset
	);

	void clean();
};

#endif // __RENDERER_HPP__