#include "Cabeca.h"

GLuint Cabeca::LoadTexture(const char* filename)
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

void Cabeca::InicializaRendering()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	quadRugged = gluNewQuadric();
	_textureIdRugged = LoadTexture(filenameRugged);

	quadRusted = gluNewQuadric();
	_textureIdRusted = LoadTexture(filenameRusted);

	quadGolden = gluNewQuadric();
	_textureIdGolden = LoadTexture(filenameGolden);

	quadGlass = gluNewQuadric();
	_textureIdGlass = LoadTexture(filenameGlass);
}

void Cabeca::InicializaLuz(void)
{
	GLfloat luzAmbiente0[4] = { 0.6,0.6,0.6,1.0 };
	GLfloat luzDifusa0[4] = { 0.9,0.9,0.9,1.0 };
	GLfloat posicaoLuz0[4] = { 0.0, 500.0, 0.0, 0.0 };

	// Especifica que a cor de fundo da janela sera preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorizacao de Gouraud
	glShadeModel(GL_SMOOTH);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente0);

	// Define os parametros das fontes de luz
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa0);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz0);

	//Habilita o uso de iluminacao
	glEnable(GL_LIGHTING);
	// Habilita as fontes de luz
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
	//glFrontFace(GL_CW);
	// Habilita blending para usar alpha
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	angle = 45;
	rot_x = 0;
	rot_y = 0;
}

void Cabeca::EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projecao
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projecao
	glLoadIdentity();
	// Especifica a projecao perspectiva
	gluPerspective(angle, fAspect, 0.1, 500);
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posicao do observador e do alvo
	gluLookAt(0, 0, 200, 0, 30, 0, 0, 1, 0);
}

void Cabeca::DesenhaCubo(GLuint _textureId, float lenghtX, float lenghtY, float height)
{
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBegin(GL_QUADS);			// Face posterior
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-lenghtX, -lenghtY, -height);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-lenghtX, lenghtY, -height);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(lenghtX, lenghtY, -height);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(lenghtX, -lenghtY, -height);
	glEnd();

	glBegin(GL_QUADS);			// Face frontal
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-lenghtX, -lenghtY, height);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(lenghtX, -lenghtY, height);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(lenghtX, lenghtY, height);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-lenghtX, lenghtY, height);
	glEnd();

	glBegin(GL_QUADS);			// Face lateral esquerda
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-lenghtX, -lenghtY, -height);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-lenghtX, -lenghtY, height);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-lenghtX, lenghtY, height);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-lenghtX, lenghtY, -height);
	glEnd();

	glBegin(GL_QUADS);			// Face lateral direita
		glTexCoord2f(1.0f, 0.0f); glVertex3f(lenghtX, -lenghtY, -height);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(lenghtX, lenghtY, -height);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(lenghtX, lenghtY, height);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(lenghtX, -lenghtY, height);
	glEnd();

	glBegin(GL_QUADS);			// Face superior
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-lenghtX, lenghtY, -height);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-lenghtX, lenghtY, height);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(lenghtX, lenghtY, height);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(lenghtX, lenghtY, -height);
	glEnd();

	glBegin(GL_QUADS);			// Face inferior
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-lenghtX, -lenghtY, -height);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(lenghtX, -lenghtY, -height);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(lenghtX, -lenghtY, height);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-lenghtX, -lenghtY, height);
	glEnd();
}

void Cabeca::DesenhaBastao(float diam_start, float diam_end, float lenght, float radius, int color)
{
	glColor4f(0.3f, 0.3f, 0.3f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, _textureIdGolden);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	gluQuadricTexture(quadGolden, TRUE);
	gluCylinder(quadGolden, diam_start, diam_end, lenght, 72, 72);
	glTranslatef(0.0f, 0.0f, lenght + radius);
	switch (color)
	{
		case 1:
			glColor4f(1.0f, 0.0f, 0.0f, 0.7f);
			break;
		case 2:
			glColor4f(0.0f, 1.0f, 0.0f, 0.7f);
			break;
		case 3:
			glColor4f(0.0f, 0.0f, 1.0f, 0.7f);
			break;
		case 4:
			glColor4f(1.0f, 1.0f, 0.0f, 0.7f);
			break;
	}
	glBindTexture(GL_TEXTURE_2D, _textureIdGlass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	gluQuadricTexture(quadGlass, TRUE);
	gluSphere(quadGlass, radius, 72, 72);
}

void Cabeca::DesenhaParteCoroa(float base, float top, float length, float height)
{
	glColor4f(0.3f, 0.3f, 0.3f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, _textureIdGolden);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-base, 0, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-top, length, height);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(top, length, height);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(base, 0, 0);
	glEnd();
}

void Cabeca::cabecaHandleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27:
			exit(0);
			break;
		case 'f':
			fundo = ~fundo;
			glutPostRedisplay();
			break;
		default:
			return;
	}
}

void Cabeca::cabecaHandleArrowpress(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP:
			rot_x += 6;
			break;
		case GLUT_KEY_DOWN:
			rot_x -= 6;
			break;
		case GLUT_KEY_LEFT:
			rot_y -= 6;
			break;
		case GLUT_KEY_RIGHT:
			rot_y += 6;
			break;
	}
	glutPostRedisplay();
}

void Cabeca::cabecaHandleMouseEvent(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN) // Zoom-in
		{
			if (angle >= 10) angle -= 5;
		}
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN) // Zoom-out
		{
			if (angle <= 130) angle += 5;
		}
	}
	//EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void Cabeca::cabecaDrawScene(void)
{
	EspecificaParametrosVisualizacao();

	// Desenha esfera no fundo/background
	if (fundo) {
		glPushMatrix();
			glTranslatef(10.0, 0, -80.0f);
			glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
			glutSolidSphere(30.0f, 72, 72);
		glPopMatrix();
	}

	// Aplica rotacoes (pan)

	glRotatef(rot_x, 1, 0, 0);
	glRotatef(rot_y, 0, 1, 0);

	// Desenha pescoco (cone)
	glColor4f(0.3f, 0.3f, 0.3f, 1.0f);
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glBindTexture(GL_TEXTURE_2D, _textureIdRugged);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadRugged, TRUE);
		gluCylinder(quadRugged, 10.0f, 7.5f, 21.5f, 72, 72);
		glTranslatef(0.0f, 0.0f, 21.5f);

		glColor4f(0.3f, 0.3f, 0.3f, 1.0f);
		glBindTexture(GL_TEXTURE_2D, _textureIdRusted);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadRusted, TRUE);
		gluCylinder(quadRusted, 7.5f, 2.0f, 17.0f, 72, 72);
	glPopMatrix();
	glTranslatef(0.0f, 37.0f, 0.0f);

	// Desenha haste para os olhos (paralelepipedo)
	glColor4f(0.3f, 0.3f, 0.3f, 1.0f);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, posicaoCabeca);
		DesenhaCubo(_textureIdGolden, 30.0f, 3.0f, 1.5f);
	glPopMatrix();

	// Desenha olhos (esferas)
	glColor4f(1.0f, 1.0f, 0.3f, 0.8f);
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(-25.0, 0, 2.0);
		glBindTexture(GL_TEXTURE_2D, _textureIdGlass);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadGlass, TRUE);
		gluSphere(quadGlass, 3.0f, 72, 72);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(25.0, 0, 2.0);
		glBindTexture(GL_TEXTURE_2D, _textureIdGlass);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadGlass, TRUE);
		gluSphere(quadGlass, 3.0f, 72, 72);
	glPopMatrix();

	// Desenha bastoes (cilindros e esferas)
	glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(0.0f, -7.0f, 0.0f);
		glRotatef(30.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(3.0f, 1.0f, 0.0f, 0.0f);
		DesenhaBastao(1.0f, 0.5f, 25.0f, 1.5, 1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(0.0f, -7.0f, 0.0f);
		glRotatef(75.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(-3.0f, 1.0f, 0.0f, 0.0f);
		DesenhaBastao(1.0f, 0.5f, 25.0f, 1.5, 4);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(0.0f, -7.0f, 0.0f);
		glRotatef(120.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(3.0f, 1.0f, 0.0f, 0.0f);
		DesenhaBastao(1.0f, 0.5f, 25.0f, 1.5, 2);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(0.0f, -7.0f, 0.0f);
		glRotatef(165.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(-3.0f, 1.0f, 0.0f, 0.0f);
		DesenhaBastao(1.0f, 0.5f, 25.0f, 1.5, 3);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(0.0f, -7.0f, 0.0f);
		glRotatef(210.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(3.0f, 1.0f, 0.0f, 0.0f);
		DesenhaBastao(1.0f, 0.5f, 25.0f, 1.5, 1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(0.0f, -7.0f, 0.0f);
		glRotatef(255.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(-3.0f, 1.0f, 0.0f, 0.0f);
		DesenhaBastao(1.0f, 0.5f, 25.0f, 1.5, 4);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(0.0f, -7.0f, 0.0f);
		glRotatef(300.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(3.0f, 1.0f, 0.0f, 0.0f);
		DesenhaBastao(1.0f, 0.5f, 25.0f, 1.5, 2);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(0.0f, -7.0f, 0.0f);
		glRotatef(345.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(-3.0f, 1.0f, 0.0f, 0.0f);
		DesenhaBastao(1.0f, 0.5f, 25.0f, 1.5, 3);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(15.0f, 2.0f, 0.0f);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		DesenhaBastao(1.0f, 0.5f, 5.0f, 1.5, 1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glTranslatef(-15.0f, 2.0f, 0.0f);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		DesenhaBastao(1.0f, 0.5f, 5.0f, 1.5, 4);
	glPopMatrix();

	// Desenha coroa
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glColor4f(0.3f, 0.3f, 0.3f, 1.0f);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glBindTexture(GL_TEXTURE_2D, _textureIdRusted);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTranslatef(0.0f, 0.0f, 3.0f);
		gluCylinder(quadRusted, 0.1f, 10.0f, 2.0f, 72, 72);
		glTranslatef(0.0f, 0.0f, 2.0f);
		glBindTexture(GL_TEXTURE_2D, _textureIdGolden);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadGolden, TRUE);
		gluDisk(quadGolden, 0.0f, 10.0f, 72, 72);
		glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	glPopMatrix();

	// Desenha as partes da coroa
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glRotatef(30.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 5.0f, 9.0f);
		DesenhaParteCoroa(2.0f, 5.0f, 6.0f, 5.0f);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glRotatef(75.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 5.0f, 9.0f);
		DesenhaParteCoroa(2.0f, 5.0f, 6.0f, 5.0f);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glRotatef(120.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 5.0f, 9.0f);
		DesenhaParteCoroa(2.0f, 5.0f, 6.0f, 5.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glRotatef(165.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 5.0f, 9.0f);
		DesenhaParteCoroa(2.0f, 5.0f, 6.0f, 5.0f);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glRotatef(210.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 5.0f, 9.0f);
		DesenhaParteCoroa(2.0f, 5.0f, 6.0f, 5.0f);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glRotatef(255.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 5.0f, 9.0f);
		DesenhaParteCoroa(2.0f, 5.0f, 6.0f, 5.0f);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glRotatef(300.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 5.0f, 9.0f);
		DesenhaParteCoroa(2.0f, 5.0f, 6.0f, 5.0f);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glRotatef(345.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 5.0f, 9.0f);
		DesenhaParteCoroa(2.0f, 5.0f, 6.0f, 5.0f);
	glPopMatrix();

	// Desenha cabeca (elipsoide transparente)
	glEnable(GL_CULL_FACE);
	glColor4f(0.4f, 0.4f, 0.4f, 0.5f);
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, posicaoCabeca);
		glScalef(1.0f, 0.4f, 1.0f);
		glBindTexture(GL_TEXTURE_2D, _textureIdGlass);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadGlass, TRUE);
		gluSphere(quadGlass, 40.0f, 72, 72);
		glDisable(GL_CULL_FACE);
	glPopMatrix();
}

void Cabeca::cabecaAlteraJanela(GLsizei w, GLsizei h)
{
	fAspect = (GLfloat)w / (GLfloat)h;
}

