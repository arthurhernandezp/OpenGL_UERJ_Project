#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "RgbImage.h"

class Garra
{
public:
	Garra() = default;

	void initRendering(void);
	GLuint loadTexture(const char* filename);
	void drawSphere(float diameter);
	void drawDisk(float diameterInner, float diameterOuter);
	void drawCone(float diameter, float lenght);
	void drawCylinder(float diameter, float lenght);

	void garraHandleKeypress(unsigned char key, int x, int y);
	void garraDrawScene(void);

private:
	const char* filenameTexMetal1 = "../resource/metalTexture1.bmp";

	GLuint _textureIdMetal1;
	GLuint _textureIdSphere;
	GLuint _textureIdCylinder;
	GLUquadric* quadSphere;
	GLUquadric* quadCylinder;

	bool textureOn = true;

	//float diameterCylinder = 0.3;
	//float diameterSphere = 0.4;
	//float sizeArm = 4.5;
	//float sizeForearm = 3.0;
	//float sizeHand = 2.0;
	//float sizeClampPart = 1.0;
	//float diameterBase = 2.0;
	//float heightBase = 0.5;

	// Novas dimensoes = antigaDimensoes * 10

	float diameterCylinder = 3;
	float diameterSphere = 4;
	float sizeArm = 40.5;
	float sizeForearm = 30.0;
	float sizeHand = 20.0;
	float sizeClampPart = 10.0;
	float diameterBase = 20.0;
	float heightBase = 5;

	float eyeDistance = 20.0;
	float eyeX;
	float eyeY;
	float eyeZ;
	float viewAngleX = 0.0;
	float viewAngleZ = 15.0;

	float angleArm = 90.0;
	float angleForearm = 90.0;
	float angleHand = 0.0;
	float angleClampZ = 0.0;
	float angleClampY = 0.0;
};
