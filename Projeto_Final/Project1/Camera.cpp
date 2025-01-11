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
	gluLookAt(0, 0, 400, 0, 30, 0, 0, 1, 0);
}



void Camera::update()
{
	glLoadIdentity();
	EspecificaParametrosVisualizacao();
	// Aplica rotacoes (pan)
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


void Camera::cameraHandleMouseEvent(int button, int state, int x, int y)
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