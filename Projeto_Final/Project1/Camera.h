#pragma once
#pragma once
#include <stdlib.h>
#include <gl/glut.h>
#include <iostream>
class Camera
{
public:
	Camera(GLfloat angle, GLfloat rot_x, GLfloat rot_y);
	void update(void);
	void cameraAlteraJanela(GLsizei w, GLsizei h);
	void cameraHandleMouseEvent(int button, int state, int x, int y);
	void cameraHandleArrowpress(int key, int x, int y);
	void cameraHandleMotion(int x, int y);

private:
	void EspecificaParametrosVisualizacao(void);
	GLfloat angle{};
	GLfloat fAspect{};
	GLfloat rot_x{};
	GLfloat rot_y{};
	int xNovo{}; int xVelho{};
	int yNovo{}; int yVelho{};

	enum
	{
		BOTAO_ESQUERDO_CIMA,
		BOTAO_ESQUERDO_BAIXO,
		BOTAO_DIREITO_CIMA,
		BOTAO_DIREITO_BAIXO
	};

	int estadoMouse;
};

