#include "container.h"
#include <stdio.h>
#include "globalscope.h"

RE_GameContainer::RE_GameContainer()
{
	//window = nullptr;
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
	Globals::window = SDL_CreateWindow("Real Engine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,sw,sh,SDL_WINDOW_OPENGL);
	printf("Window intitialized\n");
	if (Globals::window == nullptr) {
		printf("Fatal error! We're so fucked! (container.cpp, CreateWindow)");
		SDL_Quit();
	}

	//RE_GameLoop gameloop(window);

	SDL_GLContext yourmom = SDL_GL_CreateContext(Globals::window);
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