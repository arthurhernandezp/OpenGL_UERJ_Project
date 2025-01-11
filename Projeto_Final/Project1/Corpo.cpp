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

void Corpo::desenhaPainelControle()
{
	//Botoes
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	glPushMatrix();
		glTranslatef(-5.0f, -75.0f, 52.0f); //botao direito BRANCO
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(0.2f, 1.0f, 1.0f);
		glutSolidSphere(5.0f, 42, 42);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(8.0f, -75.0f, 52.0f); //botao direito BRANCO
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(0.2f, 1.0f, 1.0f);
		glutSolidSphere(5.0f, 42, 42);
	glPopMatrix();

	glColor4f(0.1f, 0.1f, 0.1f, 1.0f); //painel base
	glPushMatrix();
		glTranslatef(2.0f, -85.0f, 49.0f);  // Cubo
		glScalef(1.0f, 1.0f, 0.1f);
		glutSolidCube(35.0f);
	glPopMatrix();


	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //VERDE
	glPushMatrix();
		glTranslatef(-10.0f, -90.0f, 52.0f);  // Cubo
		glScalef(1.0f, 1.0f, 0.1f);
		glutSolidCube(7.0f);
	glPopMatrix();

	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //VERMELHO
	glPushMatrix();
		glTranslatef(-2.0f, -90.0f, 52.0f);  // Cubo
		glScalef(1.0f, 1.0f, 0.1f);
		glutSolidCube(7.0f);
	glPopMatrix();

	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //AMARELO
	glPushMatrix();
		glTranslatef(6.0f, -90.0f, 52.0f);  // Cubo
		glScalef(1.0f, 1.0f, 0.1f);
		glutSolidCube(7.0f);
	glPopMatrix();

	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //AZUL
	glPushMatrix();
		glTranslatef(14.0f, -90.0f, 52.0f);  // Cubo
		glScalef(1.0f, 1.0f, 0.1f);
		glutSolidCube(7.0f);
	glPopMatrix();
}

void Corpo::desenhaCintura()
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
}

void Corpo::corpoHandleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'z':
		angleCorpo += 3;
		if (angleCorpo >= 360) angleCorpo = 0;
		glutPostRedisplay();
		break;
	}

}

void Corpo::corpoDrawScene(void)
{
	glPushMatrix();
		glRotatef(angleCorpo, 0.0f, 1.0f, 0.0f);
		desenhaOmbro();
		desenhaTronco();
		desenhaPainelControle();
		desenhaCintura();
	glPopMatrix();
}
