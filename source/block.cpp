
#include <GL/glew.h>
#include "block.h"

RE_Block::RE_Block() {

}

RE_Block::~RE_Block() {

}

// More code stolen
float cube_vert[] = {
    // Front face
    -0.5, -0.5,  0.5,
     0.5, -0.5,  0.5,
     0.5,  0.5,  0.5,
    -0.5,  0.5,  0.5,
    
    // Back face
    -0.5, -0.5, -0.5,
    -0.5,  0.5, -0.5,
     0.5,  0.5, -0.5,
     0.5, -0.5, -0.5,
    
    // Left face
    -0.5, -0.5, -0.5,
    -0.5, -0.5,  0.5,
    -0.5,  0.5,  0.5,
    -0.5,  0.5, -0.5,
    
    // Right face
     0.5, -0.5, -0.5,
     0.5,  0.5, -0.5,
     0.5,  0.5,  0.5,
     0.5, -0.5,  0.5,
    
    // Top face
    -0.5,  0.5, -0.5,
    -0.5,  0.5,  0.5,
     0.5,  0.5,  0.5,
     0.5,  0.5, -0.5,
    
    // Bottom face
    -0.5, -0.5, -0.5,
     0.5, -0.5, -0.5,
     0.5, -0.5,  0.5,
    -0.5, -0.5,  0.5,
};

unsigned char cube_inds[] = {
    // Front face
    0, 1, 2, 2, 3, 0,
    // Back face
    4, 5, 6, 6, 7, 4,
    // Left face
    8, 9, 10, 10, 11, 8,
    // Right face
    12, 13, 14, 14, 15, 12,
    // Top face
    16, 17, 18, 18, 19, 16,
    // Bottom face
    20, 21, 22, 22, 23, 20,
};

float cube_norm[] = {
    // Front face
    0.0,  0.0,  1.0,
    0.0,  0.0,  1.0,
    0.0,  0.0,  1.0,
    0.0,  0.0,  1.0,

    // Back face
    0.0,  0.0, -1.0,
    0.0,  0.0, -1.0,
    0.0,  0.0, -1.0,
    0.0,  0.0, -1.0,

    // Left face
   -1.0,  0.0,  0.0,
   -1.0,  0.0,  0.0,
   -1.0,  0.0,  0.0,
   -1.0,  0.0,  0.0,

    // Right face
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,

    // Top face
    0.0,  1.0,  0.0,
    0.0,  1.0,  0.0,
    0.0,  1.0,  0.0,
    0.0,  1.0,  0.0,

    // Bottom face
    0.0, -1.0,  0.0,
    0.0, -1.0,  0.0,
    0.0, -1.0,  0.0,
    0.0, -1.0,  0.0,
};
//yummy code

void RE_Block::render(int r, int g, int b, float transparency) {
    //int color = colorGrab(colorIndex, 0);
    //int r = getHex_value(color, 0);
    //int g = getHex_value(color, 1);
    //int b = getHex_value(color, 2);
    
    glBegin(GL_TRIANGLES);
    //glSetColor(r, g, b, transparency);
    for (unsigned int i = 0; i < sizeof(cube_inds) / sizeof(cube_inds[0]); i += 4) {
        for (unsigned int j = 0; j < 4; ++j) {
            unsigned int index = cube_inds[i + j];
            unsigned int indVr = index * 3;
            unsigned int indexL = cube_inds[i + j] / 4;
            
            glNormal3f(cube_norm[indVr + 1], cube_norm[indVr + 2], cube_norm[indVr]);
            glVertex3f(cube_vert[indVr + 1], cube_vert[indVr + 2], cube_vert[indVr]); 
        }
    }
    glEnd();
}