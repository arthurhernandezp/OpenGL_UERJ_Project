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

	void desenhaRoda();
	void desenhaSuporteRoda();

	void pernaHandleKeypress(unsigned char key, int x, int y);
	void pernaDrawScene(void);

private:
	float angleRoda{ 0.0f };

	const char* filenameRusted = "../resource/texture_rusted_metal.bmp"; //image file with texture
	GLuint _textureIdRusted; //The id of texture
	GLUquadric* quadRusted = nullptr;

	const char* filenameRugged = "../resource/texture_rugged_metal.bmp"; //image file with texture
	GLUquadric* quadRugged = nullptr;
	GLuint _textureIdRugged; //The id of texture
};