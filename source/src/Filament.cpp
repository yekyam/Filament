#include "../include/Filament.hpp"

Filament::Filament() : window(nullptr), screen_width(0), screen_height(0)
{
}

Filament::FilamentErrors Filament::setup(size_t WIDTH, size_t HEIGHT, const std::string &window_title = "Filament")
{
	// init glfw
	glfwInit();

	// init opengl to version 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// don't resize window - change in the future
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	this->window = glfwCreateWindow(WIDTH, HEIGHT, window_title.c_str(), nullptr, nullptr);
	glfwGetFramebufferSize(this->window, &this->screen_width, &this->screen_height);

	if (!this->window)
	{
		return FilamentErrors::UnableToSetupWindow;
	}

	return FilamentErrors::Success;
}

void Filament::run()
{
}