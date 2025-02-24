#include "Robo.h"
#include "Camera.h"

Robo robo;
Camera camera(45, 0, 0);

void Desenha(void);
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void GerenciaMouse(int button, int state, int x, int y);
void GerenciaTeclado(unsigned char key, int x, int y);
void GerenciaSetas(int key, int x, int y);
void GerenciaMovimentoMouse(int x, int y);

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(700, 350);
	glutCreateWindow("Projeto Robo");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(GerenciaTeclado);
	glutSpecialFunc(GerenciaSetas);
	glutMotionFunc(GerenciaMovimentoMouse);
	robo.roboInicializa();
	glutMainLoop();
}

void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	glPushMatrix();
	camera.update();
	robo.roboDrawScene();
	glPopMatrix();
	glutSwapBuffers();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisao por zero
	if (h == 0) h = 1;
	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
	// Calcula a correcao de aspecto
	camera.cameraAlteraJanela(w, h);
}

void GerenciaMouse(int button, int state, int x, int y)
{
	camera.cameraHandleMouseEvent(button, state, x, y);
}

void GerenciaTeclado(unsigned char key, int x, int y)
{
	robo.roboHandleKeypress(key, x, y);
}

void GerenciaSetas(int key, int x, int y)
{
	camera.cameraHandleArrowpress(key, x, y);
}

void GerenciaMovimentoMouse(int x, int y)
{
	camera.cameraHandleMotion(x, y);
}
