#include "Perna.h"

void Perna::initRendering(void)
{
	quadRusted = gluNewQuadric();
	_textureIdRusted = loadTexture(filenameRusted);
	quadRugged = gluNewQuadric();
	_textureIdRugged = loadTexture(filenameRugged);
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

void Perna::desenhaRoda()
{
	glBindTexture(GL_TEXTURE_2D, _textureIdRugged);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	gluQuadricTexture(quadRugged, 1);
	//Roda direita  
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glPushMatrix();
		glTranslatef(42.0f, -160.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(1.1f, 0.5f, 1.1f);  // achatando
		gluQuadricTexture(quadRugged, TRUE);
		gluCylinder(quadRugged, 30.0f, 50.0f, 10.0f, 32, 32);
	glPopMatrix();

	//Roda direita  
	glPushMatrix();
		glTranslatef(52.0f, -160.0f, 0.0f);
		glRotatef(90.0f, 0.0f,1.0f, 0.0f);
		glScalef(1.1f, 0.5f, 1.1f);  // achatando
		gluQuadricTexture(quadRugged, TRUE);
		gluCylinder(quadRugged, 50.0f, 30.0f, 10.0f, 32, 32);
	glPopMatrix();

	//Roda esquerda  
	glPushMatrix();
		glTranslatef(-52.0f, -160.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(1.1f, 0.5f, 1.1f);  // achatando
		//gluQuadricTexture(quadRugged, TRUE);
		gluCylinder(quadRugged, 30.0f, 50.0f, 10.0f, 32, 32);
	glPopMatrix();

	//Roda esquerda  
	glPushMatrix();
		glTranslatef(-42.0f, -160.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(1.1f, 0.5f, 1.1f);  // achatando
		//gluQuadricTexture(quadRugged, TRUE);
		gluCylinder(quadRugged, 50.0f, 30.0f, 10.0f, 32, 32);
	glPopMatrix();
}

void Perna::desenhaSuporteRoda()
{
	glPushMatrix(); //Retangulo esquerdo
		glColor4f(1.0f, 1.0f, 1.0f, 0.3f);
		glTranslatef(-22.0f, -155.0f, 0.0f);  // Cubo;
		glScalef(0.5f, 0.2f, 1.0f);
		glutSolidCube(80.0f);
	glPopMatrix();

	glPushMatrix(); //Retangulo direito
		glColor4f(1.0f, 1.0f, 1.0f, 0.3f);
		glTranslatef(22.0f, -155.0f, 0.0f);  // Cubo
		glScalef(0.5f, 0.2f, 1.0f);
		gluQuadricTexture(quadRusted, TRUE);
		glutSolidCube(80.0f);
	glPopMatrix();
}

void Perna::pernaHandleKeypress(unsigned char key, int x, int y)
{

}

void Perna::pernaDrawScene(void)
{
	desenhaRoda();
	
	desenhaSuporteRoda();
}
