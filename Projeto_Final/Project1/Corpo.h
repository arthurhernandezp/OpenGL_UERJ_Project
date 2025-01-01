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

	void corpoHandleKeypress(unsigned char key, int x, int y);
	void corpoDrawScene(void);

private:

};

