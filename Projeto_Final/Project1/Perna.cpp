#include "Perna.h"

void Perna::initRendering(void)
{
	_textureIdRusted = loadTexture(filenameRusted);
}

GLuint Perna::loadTexture(const char* filename)
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

void Perna::pernaHandleKeypress(unsigned char key, int x, int y)
{
}

void Perna::pernaDrawScene(void)
{
	  //Base pes 0
	glColor4f(1.0f, 0.0f, 0.0f, 0.5f);

	glPushMatrix();
		glTranslatef(0.0f, -120.0f, 0.0f); // para chegar na base inf do amarelo 115
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

		glScalef(1.0f, 0.2f, 1.0f);  // achatando
		glutSolidSphere(50.0f, 42, 42);
	glPopMatrix();

	glColor4f(0.0f, 1.0f, 0.0f, 0.5f);

	//Base pes 1
	glPushMatrix();
		glTranslatef(0.0f, -130.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(1.0f, 0.2f, 1.0f);  // achatando
		glutSolidSphere(50.0f, 42, 42);
	glPopMatrix();

	glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
	//Base pes 2    
	glPushMatrix();
		glTranslatef(0.0f, -140.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(1.0f, 0.2f, 1.0f);  // achatando
		glutSolidSphere(50.0f, 42, 42);
	glPopMatrix();

	glColor4f(1.0f, 0.0f, 1.0f, 0.5f);

	glPushMatrix(); //Retangulo esquerdo
		glTranslatef(-22.0f, -155.0f, 0.0f);  // Cubo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureIdRusted);
		glScalef(0.5f, 0.2f, 1.0f);
		glutSolidCube(80.0f);
	glPopMatrix();

	glPushMatrix(); //Retangulo direito
		glTranslatef(22.0f, -155.0f, 0.0f);  // Cubo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureIdRusted);
		glScalef(0.5f, 0.2f, 1.0f);
		glutSolidCube(80.0f);
	glPopMatrix();

	//Pes

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	glPushMatrix(); //Pe esquerdo
		glTranslatef(-22.0f, -170.0f, 0.0f);
		glScalef(0.5f, 0.2f, 1.0f);
		glutSolidCube(50.0f);
	glPopMatrix();
}
