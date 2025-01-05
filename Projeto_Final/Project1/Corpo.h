#pragma once

#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "RgbImage.h"

class Corpo
{
public:
	Corpo() = default;

	void initRendering(void);
	GLuint loadTexture(const char* filename);

	void desenhaOmbro();
	void desenhaTronco();

	void corpoHandleKeypress(unsigned char key, int x, int y);
	void corpoDrawScene(void);

private:

	float angleCorpo{0.0f};

	const char* filenameRugged = "../resource/texture_rugged_metal.bmp"; //image file with texture
	const char* filenameRusted = "../resource/texture_rusted_metal.bmp"; //image file with texture

	GLUquadric* quadRugged = nullptr;
	GLUquadric* quadRusted = nullptr;

	GLuint _textureIdRusted; //The id of texture
	GLuint _textureIdRugged; //The id of texture

};

