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

	float diameterCylinder = 0.3;
	float diameterSphere = 0.4;
	float sizeArm = 4.5;
	float sizeForearm = 3.0;
	float sizeHand = 2.0;
	float sizeClampPart = 1.0;
	float diameterBase = 2.0;
	float heightBase = 0.5;

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
/*
void garraHandleKeypress(unsigned char key, int x, int y, Garra & garra)
{
	switch (key) 
	{
		case 27: //Escape key
			exit(0);
		case 'w': //Increase view angle z axis
			if (garra.viewAngleZ < 180) garra.viewAngleZ += 3;
			glutPostRedisplay();
			break;
		case 'z': //Decrease view angle z axis
			if (garra.viewAngleZ > 0) garra.viewAngleZ -= 3;
			glutPostRedisplay();
			break;
		case 'a': //Decrease view angle x axis
			if (garra.viewAngleX > 0) garra.viewAngleX -= 3;
			glutPostRedisplay();
			break;
		case 's': //Increase view angle x axis
			if (garra.viewAngleX < 180) garra.viewAngleX += 3;
			glutPostRedisplay();
			break;
		case 't': //Use texture or not
			garra.textureOn = !(garra.textureOn);
			glutPostRedisplay();
			break;
		case '1': //Increase arm angle
			garra.angleArm += 3;
			if (garra.angleArm >= 360) garra.angleArm = 0;
			glutPostRedisplay();
			break;
		case '2': //Decrease arm angle
			garra.angleArm -= 3;
			if (garra.angleArm <= 0) garra.angleArm = 360;
			glutPostRedisplay();
			break;
		case '3': //Increase forearm angle
			if (garra.angleForearm < 90) garra.angleForearm += 3;
			glutPostRedisplay();
			break;
		case '4': //Decrease forearm angle
			if (garra.angleForearm > -90) garra.angleForearm -= 3;
			glutPostRedisplay();
			break;
		case '5': //Increase clamp angle y axis
			if (garra.angleClampY < 60) garra.angleClampY += 3;
			glutPostRedisplay();
			break;
		case '6': //Decrease clamp angle y axis
			if (garra.angleClampY > 0) garra.angleClampY -= 3;
			glutPostRedisplay();
			break;
		}
}*/