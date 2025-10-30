#include "gameloop.h"
#include "globalscope.h"
#include <GL/glew.h>
#include <stdio.h>
#include <SDL2/SDL.h>
// RE_GameLoop -- basis for all future gameplay components
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

void RE_GameLoop::gameLoop() {
	printf("Entering gameloop\n");
	while (activeState != RE_GameState::BEGONE) {
		processInput();
		graphicsProcess();
	}
	printf("Cleaning up\n");
	// segfault jumpscare
	//SDL_Quit();
}

void RE_GameLoop::graphicsProcess() {
	#ifndef EMSCRIPTEN
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// More code blatently stolen (not afraid to admit that)
	// THIS CODE DOESN'T WORK! TODO: FIX IT
	glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_CULL_FACE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST); 

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    // lmao
	//printf("Begin rendering blocks\n");
    //for (int i = 0; i < 1024; i++) {
    	//printf("Rendering block %i\n",i);
    	//Globals::blocks[i].render(0,0,0,1.0f);
    //}
    //printf("Done rendering blocks\n");
	glPopMatrix();
    glFlush();
    #endif
	if (Globals::window != nullptr) {
		SDL_GL_SwapWindow(Globals::window);
	}
}

void RE_GameLoop::processInput() { // Note to self: ISO C++ doesn't exactly like it when you do that whole "no type" [__] [_____]
	//todo: process input
	SDL_Event* event = new SDL_Event(); // SDL_Event fix courtesy of https://www.reddit.com/r/CodingHelp/comments/u37s4t/
	int r = SDL_PollEvent(event);
	if (r == 1) {
		if (event->type == SDL_QUIT) { // nevermind, apparently this is where our nuke 'em is happening.
			printf("Leaving gameloop\n");
			activeState = RE_GameState::BEGONE;
		}
		if (event->type == SDL_MOUSEMOTION) {
			//printf("X: %i\n",event->motion.x);
			//printf("Y: %i\n",event->motion.y);
		}
		if (event->type == SDL_KEYDOWN) {

		}
	}
	// free(event); No. Bad Donovan. We don't free event.
}