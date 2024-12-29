#include "Robo.h"

Robo::Robo()
{
	garra = std::make_unique<Garra>();
	cabeca = std::make_unique<Cabeca>();
}

void Robo::roboInicializa()
{
	garra->initRendering();
	cabeca->InicializaLuz();
	cabeca->InicializaRendering();
}

void Robo::roboHandleKeypress(unsigned char key, int x, int y)
{
	garra->garraHandleKeypress(key, x, y);
	cabeca->cabecaHandleKeypress(key, x, y);
}

void Robo::roboHandleArrowpress(int key, int x, int y)
{
	cabeca->cabecaHandleArrowpress(key, x, y);
}

void Robo::roboHandleMouseEvent(int button, int state, int x, int y)
{
	cabeca->cabecaHandleMouseEvent(button, state, x, y);
}

void Robo::roboDrawScene(void)
{
	cabeca->cabecaDrawScene();
	garra->garraDrawScene();
}

void Robo::roboAlteraJanela(GLsizei w, GLsizei h)
{
	cabeca->cabecaAlteraJanela(w, h);
}
