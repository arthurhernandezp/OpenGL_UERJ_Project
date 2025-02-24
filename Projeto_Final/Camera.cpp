#include "Camera.h"

Camera::Camera(GLfloat angle, GLfloat rot_x, GLfloat rot_y)
	:angle{angle}, rot_x{rot_x}, rot_y{rot_y}
{
}


void Camera::EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projecao
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projecao
	glLoadIdentity();
	// Especifica a projecao perspectiva
	gluPerspective(angle, fAspect, 0.1, 1000);
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posicao do observador e do alvo
	gluLookAt(0 , 0 , 400, 0 + transladaX, -100 + transladaY, 0 , 0 , 1, 0);
}



void Camera::update(void)
{
	glLoadIdentity();
	EspecificaParametrosVisualizacao();
	// Aplica rotacoes (pan) para movimentação da camera
	glRotatef(rot_x, 1, 0, 0);
	glRotatef(rot_y, 0, 1, 0);
}

void Camera::cameraAlteraJanela(GLsizei w, GLsizei h)
{
	fAspect = (GLfloat)w / (GLfloat)h;
}

void Camera::cameraHandleArrowpress(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		transladaY += 15;
		break;
	case GLUT_KEY_DOWN:
		transladaY -= 15;
		break;
	case GLUT_KEY_LEFT:
		transladaX -= 15;
		break;
	case GLUT_KEY_RIGHT:
		transladaX += 15;
		break;
	}
	glutPostRedisplay();
}

void Camera::cameraHandleMotion(int x, int y)
{
	xNovo = y;
	yNovo = x;

	if(estadoMouse == Camera::BOTAO_DIREITO_BAIXO)
		(yNovo > yVelho) ? rot_y += 8 : rot_y -= 8;


	if(estadoMouse == Camera::BOTAO_ESQUERDO_BAIXO)
		(xNovo > xVelho) ? rot_x += 8 : rot_x -= 8;

	
	xVelho = xNovo;
	yVelho = yNovo;

	glutPostRedisplay();
}


void Camera::cameraHandleMouseEvent(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		(state == GLUT_DOWN) ? (estadoMouse = Camera::BOTAO_ESQUERDO_BAIXO) : (estadoMouse = Camera::BOTAO_ESQUERDO_CIMA);

	if (button == GLUT_RIGHT_BUTTON)
		(state == GLUT_DOWN) ? (estadoMouse = Camera::BOTAO_DIREITO_BAIXO) : (estadoMouse = Camera::BOTAO_DIREITO_CIMA);

	//Rodinha do mouse
	if (button == 3)
	{
		if (angle >= 10) angle -= 5;
	}
	if (button == 4)
	{
		if (angle <= 130) angle += 5;	
	}

	//EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}