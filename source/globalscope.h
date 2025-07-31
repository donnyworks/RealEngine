#pragma once

#include <SDL2/SDL.h>
#include "block.h"
#define BLOCKS_MAX 1024
namespace Globals {
extern SDL_Window* window;
extern RE_Block blocks[BLOCKS_MAX];
}