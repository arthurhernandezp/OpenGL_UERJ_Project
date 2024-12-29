#pragma once
#include "Garra.h"
#include "Cabeca.h"
class Robo
{
public:

	Robo();

	void roboInicializa();
	void roboHandleKeypress(unsigned char key, int x, int y);
	void roboHandleArrowpress(int key, int x, int y);
	void roboHandleMouseEvent(int button, int state, int x, int y);
	void roboDrawScene(void);
	void roboAlteraJanela(GLsizei w, GLsizei h);

private:
	Garra garra;
	Cabeca cabeca;
};

