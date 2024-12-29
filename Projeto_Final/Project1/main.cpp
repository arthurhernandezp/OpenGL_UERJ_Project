//#include "Garra.h"
//
//Garra garra;
//
//void handleKeypress(unsigned char key, int x, int y);
//void handleResize(int w, int h);
//void drawScene(void);
//
//int main(int argc, char** argv) 
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 800);
//	glutCreateWindow("Garra");
//
//	garra.initRendering();
//	glutDisplayFunc(drawScene);
//	glutKeyboardFunc(handleKeypress);
//	glutReshapeFunc(handleResize);
//
//	glutMainLoop();
//
//	return 0;
//}
//void handleKeypress(unsigned char key, int x, int y)
//{
//	garra.garraHandleKeypress(key, x, y);
//}
//
//void handleResize(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60.0, (float)w / (float)h, 1.0, 50.0);
//}
//
//void drawScene(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glEnable(GL_TEXTURE_2D);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	garra.garraDrawScene();
//
//	glutSwapBuffers();
//}
#include "Cabeca.h"

Cabeca cabeca;

void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cabeca.cabecaDrawScene();
	glutSwapBuffers();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisao por zero
	if (h == 0) h = 1;
	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
	// Calcula a correcao de aspecto
	cabeca.cabecaAlteraJanela(w,h);
}
void GerenciaMouse(int button, int state, int x, int y)
{
	cabeca.cabecaHandleMouseEvent(button,state,x,y);
}
void GerenciaTeclado(unsigned char key, int x, int y)
{
	cabeca.cabecaHandleKeypress(key,x,y);
}

void GerenciaSetas(int key, int x, int y)
{
	cabeca.cabecaHandleArrowpress(key, x, y);
}

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(700, 350);
	glutCreateWindow("Cabeca de Robo");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(GerenciaTeclado);
	glutSpecialFunc(GerenciaSetas);
	cabeca.InicializaLuz();
	cabeca.InicializaRendering();
	glutMainLoop();
}