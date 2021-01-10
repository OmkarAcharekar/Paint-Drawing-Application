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
