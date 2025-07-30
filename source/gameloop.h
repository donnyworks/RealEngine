#pragma once

#include <SDL2/SDL.h>

enum class RE_GameState {
	NOT_DEAD,
	FUCKED,
	BEGONE
};

class RE_GameLoop
{
	public:
		RE_GameLoop();
		RE_GameLoop(SDL_Window* _window);
		~RE_GameLoop();

		void gameLoop();
		void graphicsProcess();
		RE_GameState activeState;
	private:
		SDL_Window* window;
		void processInput(); // I have no idea what this is gonna do to the engine
};