#include "gameloop.h"
#include "globalscope.h"
#include <GL/glew.h>
#include <stdio.h>
#include <SDL2/SDL.h>
// RE_GameLoop -- basis for all future shit
RE_GameLoop::RE_GameLoop() {
	printf("Gameloop intitialized\n");
	activeState = RE_GameState::NOT_DEAD;
	//window = nullptr;
}

RE_GameLoop::RE_GameLoop(SDL_Window* _window) {
	printf("Gameloop intitialized (now with window promise)\n");
	activeState = RE_GameState::NOT_DEAD;
	if (_window != nullptr) {
		printf("We may be safe\n");
	}
	//window = _window;
}

RE_GameLoop::~RE_GameLoop() {

}

void RE_GameLoop::gameLoop() { // Note to self: ISO C++ doesn't exactly like it when you do that whole "no type" shit dumbass
	printf("Entering gameloop\n");
	while (activeState != RE_GameState::BEGONE) {
	//while (true) {
		//printf("quack\n");
		processInput();
		graphicsProcess();
	}
}

void RE_GameLoop::graphicsProcess() { // Note to self: ISO C++ doesn't exactly like it when you do that whole "no type" shit dumbass
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f,0.0f,0.0f); //This is red
	glVertex2f(0,0);
	glVertex2f(0,15);
	glVertex2f(15,0);
	glVertex2f(15,15);
	
	glEnd();

	if (Globals::window != nullptr) {
		SDL_GL_SwapWindow(Globals::window);
	}
}

void RE_GameLoop::processInput() { // Note to self: ISO C++ doesn't exactly like it when you do that whole "no type" shit dumbass
	//todo: process input
	SDL_Event* event; //fuck it we leak fuck it we leak
	int r = SDL_PollEvent(event);
	if (r == 1) {
		if (event->type == SDL_QUIT) {
			activeState = RE_GameState::BEGONE;
		}
		if (event->type == SDL_MOUSEMOTION) {
			printf("X: %i\n",event->motion.x);
			printf("Y: %i\n",event->motion.y);
		}
	}
}