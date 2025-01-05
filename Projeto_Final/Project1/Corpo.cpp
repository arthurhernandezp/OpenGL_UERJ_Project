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

void Corpo::desenhaOmbro()
{
	//Base ombros sup AZUL
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glPushMatrix();
		glTranslatef(0.0f, -35.0f, 0.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadRugged, TRUE);
		gluCylinder(quadRugged, 30.0f, 50.0f, 10.0f, 32, 32);
	glPopMatrix();

	//Base ombros inf VERMELHO
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glPushMatrix();
		glTranslatef(0.0f, -45.0f, 0.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadRugged, TRUE);
		gluCylinder(quadRugged, 50.0f, 30.0f, 10.0f, 32, 32);
	glPopMatrix();
}

void Corpo::desenhaTronco()
{
	//Tronco AMARELO
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);

	glPushMatrix();
		glTranslatef(0.0f, -55.0f, 0.0f);	
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f); 
		gluCylinder(quadRugged, 50.0f, 50.0f, 60.0f, 72, 72);
	glPopMatrix();

}

void Corpo::corpoHandleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		angleCorpo += 3;
		if (angleCorpo >= 360) angleCorpo = 0;
		break;
	}

}

void Corpo::corpoDrawScene(void)
{
	glPushMatrix();
		glRotatef(angleCorpo, 0.0f, 1.0f, 0.0f);
		desenhaOmbro();
		desenhaTronco();
	glPopMatrix();
}
