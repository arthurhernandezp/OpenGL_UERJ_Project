#include "Robo.h"

Robo::Robo()
{
	garraEsquerda = new Garra();
	garraEsquerda->setPosition(-10.0f, 0.0f, 0.0f);  
	garraEsquerda->setOrientation(180.0f);           

	garraDireita = new Garra();
	garraDireita->setPosition(10.0f, 0.0f, 0.0f);    
	garraDireita->setOrientation(0.0f);              
	garraDireita->tipoBraco = Garra::BRACO_DIREITO;

	cabeca = new Cabeca();

	corpo = new Corpo();

	perna = new Perna();
}

Robo::~Robo()
{
	delete garraEsquerda;
	delete garraDireita;
	delete cabeca;
	delete corpo;
	delete perna;
}

void Robo::roboInicializa()
{
	garraEsquerda->initRendering();

	garraDireita->initRendering();

	cabeca->InicializaLuz();
	cabeca->InicializaRendering();

	corpo->initRendering();

	perna->initRendering();
}

void Robo::roboHandleKeypress(unsigned char key, int x, int y)
{
	cabeca->cabecaHandleKeypress(key, x, y);
	garraEsquerda->garraHandleKeypress(key, x, y);
	garraDireita->garraHandleKeypress(key, x, y);
	corpo->corpoHandleKeypress(key, x, y);
	perna->pernaHandleKeypress(key, x, y);
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

	glPushMatrix();
		glTranslatef(-145.0f, -100.0f, 0.0f); 
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f); 
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
		garraEsquerda->garraDrawScene();  
	glPopMatrix();

	glPushMatrix();
		glTranslatef(150.0f, -100.0f, 0.0f);  
		glRotatef(-100.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f); 
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);  
		garraDireita->garraDrawScene(); 
	glPopMatrix();

	corpo->corpoDrawScene();

	perna->pernaDrawScene();
}

void Robo::roboAlteraJanela(GLsizei w, GLsizei h)
{
	cabeca->cabecaAlteraJanela(w, h);
}
