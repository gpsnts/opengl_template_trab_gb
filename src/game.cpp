#include "headers/game.hpp"

Render *render;
Shader selected_shader;

void debug_mat4(glm::mat4 to_view)
{
	cout << "DEBUG: " << glm::to_string(to_view) << endl;
}

Render *Game::get_render()
{
	return render;
}

Shader Game::get_shader()
{
	return selected_shader;
}

Game::~Game()
{
	cout << "Deleting render" << endl;
	delete render;
}

void Game::projection(bool enabled, bool aspect_correction)
{
	glm::mat4 projection(1.0f);
	glm::mat4 aspect(1.f);

	if (aspect_correction)
	{
		GLfloat ratio;
		GLfloat 
			xMin = -1.f, xMax = 1.f,
			yMin = -1.f, yMax = 1.f,
			zNear = -1.f, zFar = 1.f;

		if (this->ref_width >= this->ref_height)
		{
			ratio = this->ref_width / (float) this->ref_height;
			aspect =  glm::ortho(
				xMin * ratio, xMax * ratio,
				yMin,  				yMax,
				zNear, 				zFar
			);
		}
		else
		{
			ratio = this->ref_height / (float) this->ref_width;
			aspect = glm::ortho(
				xMin, 				xMax,
				yMin * ratio, yMax * ratio,
				zNear, 				zFar
			);
		}
	}
	
	if (enabled)
	{
		projection = glm::ortho(
			-1.f, 	1.f,	// X (min-max)
			-1.f, 	1.f,	// Y (min-max)
			-1.f,  	1.f   // Z (min-max)
		);
	}

	glUseProgram(selected_shader.getProgram());
	glUniformMatrix4fv(
		glGetUniformLocation(selected_shader.getProgram(), "projection"),
		1,
		GL_FALSE,
		glm::value_ptr(aspect * projection)
	);
}

void Game::transformations(bool enabled)
{
	glm::mat4 model(1.0f);

	if (enabled)
	{
		model = glm::rotate(model, (float) glfwGetTime() * -5.0f, glm::vec3(75.0f, 15.0f, 35.0f));
	}

	glUseProgram(selected_shader.getProgram());
	glUniformMatrix4fv(
		glGetUniformLocation(selected_shader.getProgram(), "model"),
		1,
		GL_FALSE,
		glm::value_ptr(model)
	);
}

void Game::init()
{
	Resources::assign_shader(
		"../src/shaders/triangle.vert",
		"../src/shaders/triangle.frag",
		"shader_uniform"
	);

	selected_shader = Resources::get_shader("shader_uniform");
	
	render = new Render(selected_shader);
	render->render_data(
		{
			this->x1.x, this->x1.y, this->x1.z,
			this->x2.x, this->x2.y, this->x2.z,
			this->x3.x, this->x3.y, this->x3.z 
		},
		{}
	);
}

void Game::build() {
	glUseProgram(selected_shader.getProgram());
		
	GLint colorLoc = glGetUniformLocation(
		selected_shader.getProgram(),
		"inputColor"
	);

	glUniform4f(colorLoc, 1.f, 0.f, 0.f, 1.f);

	glBindVertexArray(render->get_vao());

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
	glUseProgram(0);
}

void Game::events(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) cout << "Pressed A" << endl;
}