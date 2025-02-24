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

	void setPosition(float x, float y, float z);
	void setOrientation(float angleY);
	void setTextureOn(bool);

	float getAngleArm () const;
	float getangleForearm() const;
	float getSizeArm() const;

	enum
	{
		BRACO_ESQUERDO,
		BRACO_DIREITO
	};

	int tipoBraco = BRACO_ESQUERDO;

private:
	const char* filenameTexMetal1 = "../resource/metalTexture1.bmp";

	GLuint _textureIdMetal1;
	GLuint _textureIdSphere;
	GLuint _textureIdCylinder;
	GLUquadric* quadSphere;
	GLUquadric* quadCylinder;

	bool textureOn = true;

	float diameterCylinder = 9;
	float diameterSphere = 10;
	float sizeArm = 40.5;
	float sizeForearm = 40.0;
	float sizeHand = 25.0;
	float sizeClampPart = 20.0;
	float diameterBase = 0.0;
	float heightBase = -100;

	float eyeDistance = 20.0;
	float eyeX;
	float eyeY;
	float eyeZ;
	float viewAngleX = 0.0;
	float viewAngleZ = -180.0;

	float angleArm = 90.0;
	float angleForearm = 90.0;
	float angleHand = 0.0;
	float angleClampZ = 0.0;
	float angleClampY = 0.0;

	float positionX = 0.0f;
	float positionY = 0.0f;
	float positionZ = 0.0f;
	float orientationZ = 0.0f; 

};
