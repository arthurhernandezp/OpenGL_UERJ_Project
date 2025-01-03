#pragma once

#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "RgbImage.h"

class Perna
{
public:
	Perna() = default;

	void initRendering(void);
	GLuint loadTexture(const char* filename);

	void pernaHandleKeypress(unsigned char key, int x, int y);
	void pernaDrawScene(void);

private:
	const char* filenameRusted = "../resource/texture_rusted_metal.bmp"; //image file with texture
	GLuint _textureIdRusted; //The id of texture
};