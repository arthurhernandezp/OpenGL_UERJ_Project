#include "Robo.h"

Robo::Robo()
{
	garraEsquerda = std::make_unique<Garra>();
	garraEsquerda->setPosition(-10.0f, 0.0f, 0.0f);  // Lado esquerdo
	garraEsquerda->setOrientation(180.0f);           // Invertida

	garraDireita = std::make_unique<Garra>();
	garraDireita->setPosition(10.0f, 0.0f, 0.0f);    // Lado direito
	garraDireita->setOrientation(0.0f);              // Normal
	garraDireita->setTextureOn(false);
	cabeca = std::make_unique<Cabeca>();
}

void Robo::roboInicializa()
{
	garraEsquerda->initRendering();
	garraDireita->initRendering();
	cabeca->InicializaLuz();
	cabeca->InicializaRendering();
}

void Robo::roboHandleKeypress(unsigned char key, int x, int y)
{
	cabeca->cabecaHandleKeypress(key, x, y);
	garraEsquerda->garraHandleKeypress(key, x, y);
	garraDireita->garraHandleKeypress(key, x, y);
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
	// Configurações para a garra esquerda
	glPushMatrix();
		glTranslatef(-150.0f, -100.0f, 0.0f);  // Posiciona no lado esquerdo
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  // Rotaciona para apontar para fora
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);  // Rotaciona para apontar para fora
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);  // Rotaciona para apontar para fora
		garraEsquerda->garraDrawScene();  // Desenha a garra
	glPopMatrix();

	// Configurações para a garra direita
	glPushMatrix();
		glTranslatef(150.0f, -100.0f, 0.0f);  // Posiciona no lado direito
		glRotatef(-100.0f, 0.0f, 1.0f, 0.0f); // Rotaciona para apontar para fora
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);  // Rotaciona para apontar para fora
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);  // Rotaciona para apontar para fora
		garraDireita->garraDrawScene();  // Desenha a garra
	glPopMatrix();


}

void Robo::roboAlteraJanela(GLsizei w, GLsizei h)
{
	cabeca->cabecaAlteraJanela(w, h);
}
