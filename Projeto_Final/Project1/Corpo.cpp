#include "Corpo.h"

void Corpo::initRendering(void)
{
	quadRugged = gluNewQuadric();
	_textureIdRugged = loadTexture(filenameRugged);
	quadRusted = gluNewQuadric();
	_textureIdRusted = loadTexture(filenameRusted);
}

GLuint Corpo::loadTexture(const char* filename)
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

void Corpo::corpoHandleKeypress(unsigned char key, int x, int y)
{
}

void Corpo::corpoDrawScene(void)
{

//Base ombros sup AZUL
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glPushMatrix();
		glTranslatef(0.0f, -35.0f, 0.0f);
		glRotatef(90.0f, 75.0f, 0.0f, 0.0f);

		//glBindTexture(GL_TEXTURE_2D, _textureIdRugged);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		gluQuadricTexture(quadRugged, TRUE);
		gluCylinder(quadRugged, 30.0f, 50.0f, 10.0f, 32, 32);
	glPopMatrix();

	//Base ombros inf VERMELHO
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glPushMatrix();
		glTranslatef(0.0f, -45.0f, 0.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

		//glBindTexture(GL_TEXTURE_2D, _textureIdRugged);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		gluQuadricTexture(quadRugged, TRUE);
		gluCylinder(quadRugged, 50.0f, 30.0f, 10.0f, 32, 32);
	glPopMatrix();

	//Tronco AMARELO
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);

	glPushMatrix();
		glTranslatef(0.0f, -55.0f, 0.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f); // 10f do inf + 45 translacao

		gluCylinder(quadRugged, 50.0f, 50.0f, 60.0f, 72, 72);
	glPopMatrix();

	//Base pes 0
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	glPushMatrix();
		glTranslatef(0.0f, -135.0f, 0.0f); // para chegar na base inf do amarelo 115
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

		//glBindTexture(GL_TEXTURE_2D, _textureIdRugged);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glScalef(0.1f, 0.1f, 1.0f);  // achatando
		glutSolidSphere(50.0f, 42, 42);
	glPopMatrix();


	//Base pes 1
	glPushMatrix();
		glTranslatef(0.0f, -140.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

		//glBindTexture(GL_TEXTURE_2D, _textureIdRugged);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glScalef(0.1f, 0.1f, 1.0f);  // achatando
		glutSolidSphere(50.0f, 42, 42);
	glPopMatrix();

	//Base pes 1	
	glPushMatrix();
		glTranslatef(0.0f, -145.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

		//glBindTexture(GL_TEXTURE_2D, _textureIdRugged);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glScalef(0.1f, 0.1f, 1.0f);  // achatando
		glutSolidSphere(50.0f, 42, 42);
	glPopMatrix();


	/*
	glPushMatrix();
		glTranslatef(0.0f, -150.0f, 0.0f);
	glPopMatrix();

	//glColor4f(0.0f, 1.0f, 0.0f, 1.0f);

	glPushMatrix();
		glTranslatef(0.0f, -155.0f, -30.0f);

		glBindTexture(GL_TEXTURE_2D, _textureIdRugged);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadRugged, TRUE);

		glScalef(1.0f, 0.2f, 1.0f);
		glutSolidCube(90.0f);
	glPopMatrix(); */

	glPushMatrix();
		glTranslatef(0.0f, -155.0f, -30.0f);  // Cubo

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureIdRusted);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glScalef(1.0f, 0.2f, 0.5f);
		glutSolidCube(90.0f);

	glPopMatrix();
}
