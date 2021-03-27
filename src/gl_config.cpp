#include "headers/gl_config.hpp"

bool gl_config::check_window_creation(GLFWwindow *window_reference)
{
	if (window_reference == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return false;
	}
	return true;
}

bool gl_config::init_glad()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
		return false;
	}
	return true;
}

bool gl_config::init_glfw()
{
	if (!glfwInit())
	{
		cerr << "Cann't init GLFW" << endl;;
		return false;
	}
	return true;
}

void gl_config::set_opengl_version_profile()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void gl_config::frames_per_second(GLFWwindow *window_reference)
{
	static double previous = 0.0;
	static int count = 0;
	double elapsed, current = glfwGetTime();

	elapsed = current - previous;

	if (elapsed > 0.25) // 4x p/sec
	{
		previous = current;
		double
			frames_per_second 	= (double) count / elapsed,
			millis_per_frame 		=	1000.0 / frames_per_second;

			ostringstream out;
			out.precision(3);

			out << fixed
					<< "FPS: " << frames_per_second << " "
					<< "Elapsed time " << millis_per_frame << " ";

			glfwSetWindowTitle(window_reference, out.str().c_str());

			count = 0;
	}

	count++;
}