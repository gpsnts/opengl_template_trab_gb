#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <map>
#include <string>
#include <vector>

#include <iostream>
using namespace std;
class Renderer
{
private:
	std::map<std::string, GLuint> vaos;
	std::map<std::string, GLuint> vbos;
	std::map<std::string, GLuint> uniforms_indexes;

	std::map<std::string, std::vector<GLfloat>> data;
	std::map<std::string, std::vector<GLfloat>> positions;
	std::map<std::string, std::vector<GLfloat>> colors;
public:
	Renderer() : vaos(), vbos(), uniforms_indexes() {};

	std::map<std::string, GLuint> get_vaos();
	std::map<std::string, GLuint> get_vbos();
	std::map<std::string, GLuint> get_uniforms_indexes();

	std::map<std::string, std::vector<GLfloat>> get_uniforms_indexes();
	std::map<std::string, std::vector<GLfloat>> get_uniforms_indexes();
};

#endif // __RENDERER_HPP__