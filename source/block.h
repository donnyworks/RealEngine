#pragma once

class RE_Block {
	public:
		RE_Block();
		~RE_Block();
		void render(int r, int g, int b, float transparency);
		int x;
		int y;
		int z;
		int w;
		int h;
		int d;
};