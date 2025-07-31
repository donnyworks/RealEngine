#include "globalscope.h"
#include "block.h"

#define BLOCKS_MAX 1024

namespace Globals {
	SDL_Window* window;
	RE_Block blocks[BLOCKS_MAX];
}