#include "container.h"
#include <stdio.h>

RE_GameContainer::RE_GameContainer()
{
	window = nullptr;
	RE_GameLoop gameloop(window);
	sw = 640;
	sh = 480;
}

RE_GameContainer::~RE_GameContainer()
{
}

void RE_GameContainer::run() {
	printf("Real Engine (legit 2025)\n");
	initialize();
	gameloop.gameLoop();
}

void RE_GameContainer::initialize() {
	// INIT_EVERYTHING is awesome!!
	SDL_Init(SDL_INIT_EVERYTHING);
	window =  SDL_CreateWindow("Real Engine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,sw,sh,SDL_WINDOW_OPENGL);
	printf("Window intitialized\n");
	if (window == nullptr) {
		printf("Fatal error! We're so fucked! (container.cpp, CreateWindow)");
		SDL_Quit();
	}

	SDL_GLContext yourmom = SDL_GL_CreateContext(window);
	if (yourmom == nullptr) {
		printf("Fatal error! We're so fucked! (container.cpp, CreateContext)");
		SDL_Quit();
	}

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		printf("Fatal error! We're so fucked! (container.cpp, glewInit)");
		SDL_Quit();
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f,0.0f,0.0f, 1.0f);
}