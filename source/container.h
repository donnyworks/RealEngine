#pragma once

#include <GL/glew.h>
#include <stdio.h>
#include <SDL2/SDL.h>

// engine includes
#include "gameloop.h"
//#include "inputhandler.h" scrapped RE_InputHandler

class RE_GameContainer
{
public:
	RE_GameContainer();
	~RE_GameContainer();

	void run();

private:
	void initialize(); // Could fuck the engine over if called outside of bounds
	RE_GameLoop gameloop;
	SDL_Window* window;
	int sw;
	int sh;
};
