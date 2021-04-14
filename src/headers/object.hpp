#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#define GL_CALC_STRIDE(x) (x * sizeof(GLfloat))
#define GL_CALC_OFFSET(x) ((GLvoid *)(x * sizeof(GLfloat)))

class Object
{
private:
public:
	~Object();
	Object();

	void draw();
};

#endif // __OBJECT_HPP__
