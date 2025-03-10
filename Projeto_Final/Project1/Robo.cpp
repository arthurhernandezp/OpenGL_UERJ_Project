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

bool Robo::verificaAnguloBracos()
{
	return (garraEsquerda->getAngleArm() <= 126 && garraEsquerda->getAngleArm() >= 45);
}

bool Robo::verificaTamanhoBraco()
{
	return (garraEsquerda->getSizeArm() <= 32.5);
}

bool Robo::verificaAnguloForearm()
{
	return (garraEsquerda->getangleForearm() >= 66);
}

bool Robo::verificaBracos()
{
	return (verificaAnguloBracos() && verificaTamanhoBraco() && verificaAnguloForearm());
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
	switch (key)
	{
	case 'w':
		if (verificaBracos())
		{
			posicaoRobo += 3;
			cabeca->posicaoCabeca += 3;
			glutPostRedisplay();
		}
		break;
	case 's':
		if (verificaBracos())
		{
			posicaoRobo -= 3;
			cabeca->posicaoCabeca -= 3;
			glutPostRedisplay();
		}
		break;
	}
	cabeca->cabecaHandleKeypress(key, x, y);
	garraEsquerda->garraHandleKeypress(key, x, y);
	garraDireita->garraHandleKeypress(key, x, y);
	corpo->corpoHandleKeypress(key, x, y);
	perna->pernaHandleKeypress(key, x, y);


}

void Robo::roboDrawScene(void)
{
	glTranslatef(0.0f, 0.0f, 0.0f + posicaoRobo);
	cabeca->cabecaDrawScene();

	glPushMatrix();
		glTranslatef(-140.0f, -90.0f, 30.0f + posicaoRobo);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f); 
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
		garraEsquerda->garraDrawScene();  
	glPopMatrix();

	glPushMatrix();
		glTranslatef(140.0f, -90.0f, -10.0f + posicaoRobo);
		glRotatef(-100.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f); 
		glRotatef(-80.0f, 1.0f, 0.0f, 0.0f);  
		garraDireita->garraDrawScene(); 
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, 0.0f, 0.0f + posicaoRobo);
		corpo->corpoDrawScene();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, 0.0f, 0.0f + posicaoRobo);
		perna->pernaDrawScene();
	glPopMatrix();
}