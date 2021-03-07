#ifndef OPENGL_SETUP_
#define OPENGL_SETUP_

#include "pch/opengl_libs.hpp"
#include "game_setup.hpp"

using namespace std;

namespace OpenGLConfigSetup {
	int create_window(GLFWwindow* window);
	void set_callbacks_and_context(GLFWwindow* window);
	int init_glad();
}

#endif // !OPENGL_SETUP_