#include "Garra.h"
#define PI 3.141592654

void Garra::initRendering(void)
{
	quadSphere = gluNewQuadric();
	quadCylinder = gluNewQuadric();
	_textureIdMetal1 = loadTexture(filenameTexMetal1);
	_textureIdCylinder = _textureIdMetal1;
	_textureIdSphere = _textureIdMetal1;
}

GLuint Garra::loadTexture(const char* filename)
{
	GLuint textureId;

	RgbImage theTexMap(filename); //Image with texture

	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId);	//Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,	//Always GL_TEXTURE_2D
		0,						//0 for now
		GL_RGB,					//Format OpenGL uses for image
		theTexMap.GetNumCols(),	//Width
		theTexMap.GetNumRows(),	//Height
		0,						//The border of the image
		GL_RGB,					//GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE,		//GL_UNSIGNED_BYTE, because pixels are stored as unsigned numbers
		theTexMap.ImageData());	//The actual pixel data
	return textureId; //Returns the id of the texture
}

void Garra::drawSphere(float diameter)
{
	if (textureOn) 
	{
		glBindTexture(GL_TEXTURE_2D, _textureIdSphere);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadSphere, 1);
	}
	else
	{
		gluQuadricTexture(quadSphere, 0);
	}

	gluSphere(quadSphere, diameter, 40.0, 40.0);
}

void Garra::drawDisk(float diameterInner, float diameterOuter)
{
	if (textureOn) 
	{
		glBindTexture(GL_TEXTURE_2D, _textureIdCylinder);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadCylinder, 1);
	}
	else
	{
		gluQuadricTexture(quadCylinder, 0);
	}

	gluDisk(quadCylinder, diameterInner, diameterOuter, 40.0, 30.0);
}

void Garra::drawCone(float diameter, float lenght)
{
	if (textureOn) 
	{
		glBindTexture(GL_TEXTURE_2D, _textureIdCylinder);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadCylinder, 1);
	}
	else
	{
		gluQuadricTexture(quadCylinder, 0);
	}

	gluCylinder(quadCylinder, diameter, 0, lenght, 40.0, lenght * 30.0);
}

void Garra::drawCylinder(float diameter, float lenght)
{
	if (textureOn) 
	{
		glBindTexture(GL_TEXTURE_2D, _textureIdCylinder);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadCylinder, 1);
	}
	else
	{
		gluQuadricTexture(quadCylinder, 0);
	}

	gluCylinder(quadCylinder, diameter, diameter, lenght, 40.0, lenght * 30.0);
}

void Garra::garraHandleKeypress(unsigned char key, int x, int y)
{
	switch (key) 
	{
		case 27: //Escape key
			exit(0);
		case 'w': //Increase view angle z axis
			if (viewAngleZ < 180) viewAngleZ += 3;
			glutPostRedisplay();
			break;
		case 'z': //Decrease view angle z axis
			if (viewAngleZ > 0) viewAngleZ -= 3;
			glutPostRedisplay();
			break;
		case 'a': //Decrease view angle x axis
			if (viewAngleX > 0) viewAngleX -= 3;
			glutPostRedisplay();
			break;
		case 's': //Increase view angle x axis
			if (viewAngleX < 180) viewAngleX += 3;
			glutPostRedisplay();
			break;
		case 't': //Use texture or not
			textureOn = !textureOn;
			glutPostRedisplay();
			break;
		case '1': //Increase arm angle
			angleArm += 3;
			if (angleArm >= 360) angleArm = 0;
			glutPostRedisplay();
			break;
		case '2': //Decrease arm angle
			angleArm -= 3;
			if (angleArm <= 0) angleArm = 360;
			glutPostRedisplay();
			break;
		case '3': //Increase forearm angle
			if (angleForearm < 90) angleForearm += 3;
			glutPostRedisplay();
			break;
		case '4': //Decrease forearm angle
			if (angleForearm > -90) angleForearm -= 3;
			glutPostRedisplay();
			break;
		case '5': //Increase clamp angle y axis
			if (angleClampY < 60) angleClampY += 3;
			glutPostRedisplay();
			break;
		case '6': //Decrease clamp angle y axis
			if (angleClampY > 0) angleClampY -= 3;
			glutPostRedisplay();
			break;
	}
}

void Garra::garraDrawScene(void)
{
	eyeX = eyeDistance * cos(viewAngleZ * PI / 180) * cos(viewAngleX * PI / 180);
	eyeY = eyeDistance * cos(viewAngleZ * PI / 180) * sin(viewAngleX * PI / 180);
	eyeZ = eyeDistance * sin(viewAngleZ * PI / 180);

	if (viewAngleZ < 90)
		gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	else
		gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);

	// drawing color
	glColor3f(1.0f, 1.0f, 1.0f);

	// draws the base
	drawCylinder(diameterBase, heightBase);
	glTranslatef(0.0f, 0.0f, heightBase);
	drawDisk(diameterCylinder, diameterBase);

	// move to arm referential
	glRotatef(angleArm, 0.0f, 0.0f, 1.0f);

	//draws the arm
	drawCylinder(diameterCylinder, sizeArm);

	// move to forearm referential
	glTranslatef(0.0f, 0.0f, sizeArm + diameterSphere / 5);
	glRotatef(angleForearm, 0.0f, 1.0f, 0.0f);

	//draws the forearm
	drawSphere(diameterSphere);
	glTranslatef(0.0f, 0.0f, diameterSphere / 5);
	drawCylinder(diameterCylinder, sizeForearm);

	//move to clamp referential
	glTranslatef(0.0f, 0.0f, sizeForearm + diameterSphere / 5);
	glRotatef(angleClampZ, 0.0f, 0.0f, 1.0f);

	//draws the clamp sphere
	drawSphere(diameterSphere);
	glTranslatef(0.0f, 0.0f, diameterSphere / 2);

	glPushMatrix();

	//draws top part of clamp
	glRotatef(angleClampY + 60, 0.0f, 1.0f, 0.0f);

	drawCylinder(diameterCylinder / 3, sizeClampPart);
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
	drawSphere(diameterSphere / 3);

	glTranslatef(0.0f, 0.0f, diameterSphere / 15);
	glRotatef(-60, 0.0f, 1.0f, 0.0f);

	drawCylinder(diameterCylinder / 3, sizeClampPart);
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
	drawSphere(diameterSphere / 3);

	glTranslatef(0.0f, 0.0f, diameterSphere / 15);
	glRotatef(-60, 0.0f, 1.0f, 0.0f);
	drawCone(diameterCylinder / 3, sizeClampPart);

	glPopMatrix();
	glPushMatrix();

	//draws bottom part of clamp
	glRotatef(-angleClampY - 60, 0.0f, 1.0f, 0.0f);

	drawCylinder(diameterCylinder / 3, sizeClampPart);
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
	drawSphere(diameterSphere / 3);

	glTranslatef(0.0f, 0.0f, diameterSphere / 15);
	glRotatef(60, 0.0f, 1.0f, 0.0f);

	drawCylinder(diameterCylinder / 3, sizeClampPart);
	glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
	drawSphere(diameterSphere / 3);

	glTranslatef(0.0f, 0.0f, diameterSphere / 15);
	glRotatef(60, 0.0f, 1.0f, 0.0f);
	drawCone(diameterCylinder / 3, sizeClampPart);

	glPopMatrix();

}








