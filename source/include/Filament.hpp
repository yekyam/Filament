#pragma once

#include "EntityManager.hpp"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Filament
{
    private:
	GLFWwindow *window;
	int screen_width;
	int screen_height;

    public:
	enum class FilamentErrors {
		Success = 0,
		UnableToInitGLFW,
		UnableToInitGLEW,
		UnableToSetupWindow,
		UnableToSetupOpenGL,
	};

	// default ctor - init members to nullptr or 0
	Filament();

	// create window and opengl (3.3) rendering context
	FilamentErrors setup(size_t WIDTH, size_t HEIGHT, const std::string &window_title = "Filament");

	// run gameloop
	void run();

	// cleanup - end of filament
	void cleanup();
};