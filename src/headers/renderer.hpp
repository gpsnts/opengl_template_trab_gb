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

#include <iostream>
using namespace std;

enum Type {
	DATA,
	POSITION,
	COLOR
};

class Renderer
{
private:
	std::map<std::string, GLuint> vaos;
	std::map<std::string, GLuint> vbos;
	std::map<std::string, GLuint> layout_indexes;

	std::map<std::string, std::vector<GLfloat>> data;
	std::map<std::string, std::vector<GLfloat>> positions;
	std::map<std::string, std::vector<GLfloat>> colors;
public:
	Renderer() 
	: vaos(), vbos(), layout_indexes(),
		data(), positions(), colors() {};

	std::map<std::string, GLuint> get_vaos();
	std::map<std::string, GLuint> get_vbos();
	std::map<std::string, GLuint> get_layout_indexes();

	std::map<std::string, std::vector<GLfloat>> get_data();
	std::map<std::string, std::vector<GLfloat>> get_positions();
	std::map<std::string, std::vector<GLfloat>> get_colors();

	bool set_data(
		Type selected,
		string key_selected,
		std::initializer_list<GLfloat> payload
	);

	void bind_buffer(Type type, string key_buffer, string key_array);
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