#pragma once
#include "Garra.h"
#include "Cabeca.h"
#include "Corpo.h"
#include "Perna.h"

class Robo
{
public:

	Robo();
	~Robo();

	void roboInicializa();
	void roboHandleKeypress(unsigned char key, int x, int y);
	void roboDrawScene(void);
	float posicaoRobo{ 0.0f };
private:
	Cabeca * cabeca = nullptr;
	Corpo * corpo = nullptr;
	Garra * garraEsquerda = nullptr;
	Garra * garraDireita = nullptr;
	Perna * perna = nullptr;
};

