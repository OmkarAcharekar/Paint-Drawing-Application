#include "point.h"
#include "line.h"
#include "curve.h"
#include "polygon.h"

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <list>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#endif

using namespace std;
#define pi 3.142857

void processBorderMenu(int value)
{
	isSecond = false;
	isEraser = false;
	isRandom = false;

	ptsize = value;
}

void keyboard(unsigned char key, int xIn, int yIn)
{
	isSecond = false;
	switch (key)
	{
	//Come Out From the Paint Application when we press (q or escape)
	case 'q':
	case 27: // 27 is the esc key
		quit();
		break;
	case 'c':
		clear();
		break;
	case '+':
		if (shape == 5 && !isEraser)
		{
			if (brushSize < 16)
				brushSize += 4;
			else
			{
				cout << "[Warning] Airbrush's size cannot be larger. It is already the largest.\n";
			}
		}
		else if (isEraser)
		{
			if (eraserSize < 10)
				eraserSize += 4;
			else
			{
				cout << "[Warning] Eraser's size cannot be larger. It is already the largest.\n";
			}
		}
		break;
	case '-':
		if (shape == 5 && !isEraser)
		{
			if (brushSize > 4)
				brushSize -= 4;
			else
			{
				cout << "[Warning] Airbrush's size cannot be smaller. It is already the smallest.\n";
			}
		}
		else if (isEraser)
		{
			if (eraserSize > 2)
				eraserSize -= 4;
			else
			{
				cout << "[Warning] Eraser's size cannot be smaller. It is already the smallest.\n";
			}
		}
		break;
	case 'u':
		undo();
		break;
	case 'r':
		redo();
		break;
	}
}

int main(int argc, char **argv)
{
	//glutInit will initialize the GLUT library and negotiate a session with the window system.
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	

	glutCreateWindow("Paint"); //Giving name to our Window


	return (0);
}

void printGuide()
{
	std::cout << "#########################################################################\n"
			  << "#                    Welcome to use this Paint tool!                    #\n"
			  << "#########################################################################\n"
			 
}
