#pragma once
#include "Garra.h"
#include "Cabeca.h"
#include "Corpo.h"
#include "Perna.h"
#include "memory";	//Gilson essa biblioteca e nativa do C++ para usar ponteiros inteligentes

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
	std::unique_ptr<Cabeca> cabeca = nullptr;
	std::unique_ptr<Corpo> corpo = nullptr;
	std::unique_ptr<Garra> garraEsquerda = nullptr;
	std::unique_ptr<Garra> garraDireita = nullptr;
	std::unique_ptr<Perna> perna = nullptr;
};

