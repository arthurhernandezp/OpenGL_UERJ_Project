#pragma once
#include <stdlib.h>
#include <gl/glut.h>
#include <iostream>
#include "RgbImage.h"

class Cabeca
{
public:
	Cabeca() = default;

	GLuint LoadTexture(const char* filename);
	void InicializaRendering();
	void InicializaLuz(void);
	void EspecificaParametrosVisualizacao(void);
	void DesenhaCubo(GLuint _textureId, float lenghtX, float lenghtY, float height);
	void DesenhaBastao(float diam_start, float diam_end, float lenght, float radius, int color);
	void DesenhaParteCoroa(float base, float top, float length, float height);

	void cabecaHandleKeypress(unsigned char key, int x, int y);
	void cabecaHandleArrowpress(int key, int x, int y);
	void cabecaHandleMouseEvent(int button, int state, int x, int y);
	void cabecaDrawScene(void);
	void cabecaAlteraJanela(GLsizei w, GLsizei h);
	float posicaoCabeca{ 0.0f };

private:
	const char* filenameRugged = "../resource/texture_rugged_metal.bmp"; //image file with texture
	const char* filenameRusted = "../resource/texture_rusted_metal.bmp"; //image file with texture
	const char* filenameGolden = "../resource/texture_golden_metal.bmp"; //image file with texture
	const char* filenameGlass = "../resource/texture_glass.bmp"; //image file with texture
	GLuint _textureIdRugged; //The id of texture
	GLuint _textureIdRusted; //The id of texture
	GLuint _textureIdGolden; //The id of texture
	GLuint _textureIdGlass; //The id of texture
	GLUquadric* quadRugged = nullptr;
	GLUquadric* quadRusted = nullptr;
	GLUquadric* quadGolden = nullptr;
	GLUquadric* quadGlass = nullptr;
	GLfloat angle, fAspect, rot_x, rot_y;
	int fundo = 0;
};

