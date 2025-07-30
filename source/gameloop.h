#pragma once

#include <SDL2/SDL.h>

enum class RE_GameState {
	NOT_DEAD,
	FUCKED,
	BEGONE
};

extern SDL_Window* window;

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
		void processInput(); // I have no idea what this is gonna do to the engine
};