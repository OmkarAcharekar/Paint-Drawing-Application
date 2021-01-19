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

void processEraserSizeMenu(int value)
{
	glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
	eraserSize = value;
	isEraser = true;
}

void processEdgeMenu(int value)
{
	shape = 6;
	isEraser = false;
	isSecond = false;
	edge = value;
}

void processFilledMenu(int value)
{
	shape = 3;
	isEraser = false;
	isSecond = false;
	if (value)
		isfilled = true;
	else
		isfilled = false;
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
}

void processMainMenu(int value)
{
	switch (value)
	{
	case 0:
		quit();
		break;
	case 1:
		clear();
		break;

	case 2:
		undo();
		break;
	case 3:
		redo();
		break;
	}
}

void processRadicalBrushMenu(int value)
{
	isRadial = value == 1 ? true : false;
}

void display(void)
{
	/*
    After we made some changes in our window ,they must be immediately displayed  ,hence this function would be called
    Before calling it , it displayed the last time window , but now since we have made changes , many points have been drawn and many are removed ...
    Hence to reflect those changes .....we first clear whatever is shown on the window and then again print all the dots in the entire vector
    The alpha parameter is a number between 0.0 (fully transparent) and 1.0 (fully opaque).
    */

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // specifies the red, green, blue, and alpha values used by glClear to clear the color buffers.
	glClear(GL_COLOR_BUFFER_BIT);		  //clear buffers to preset values

	glPointSize(ptsize); //Setting the size of the point
	/*
    Ten symbolic constants are accepted: GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_QUADS, GL_QUAD_STRIP, and GL_POLYGON.
    */

	glBegin(GL_POINTS);
	for (unsigned int i = 0; i < points.size(); i++)
	{
		glColor3f(points[i].getR(), points[i].getG(), points[i].getB()); //set the current color
		glVertex2i(points[i].getX(), points[i].getY());					 //To draw the point
	}
	glEnd();

	glutSwapBuffers();
	/*
	"Buffer" here refers to the region of (video) memory where the computer renders image frames.

With double-buffering, two such buffers are used, the front buffer and the back buffer. The front buffer is the one that contains the frame you are currently seeing. The back buffer is the one in which the computer is currently busy rendering the next frame. When that rendering is done, the two buffers are swapped, instantly updating the image you see to be the next-now-current frame. The computer then again moves on to rendering a new frame in what is now its current back buffer.

This technique ensures that you only ever see fully rendered frames rather than "work in progress".

glutSwapBuffers() is the GLUT function that instructs the computer that you are done with the current frame and the buffers should be swapped so that that frame be displayed and so that you can begin working on the next.
	*/
}

void reshape(int w, int h)
{
	window_w = w;
	window_h = h;

	//Before Calling gluOrtho2D we need to have the below 2 lines of code
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Rectangular Region inWorld to be displayed
	gluOrtho2D(0, w, 0, h); //( width_start , height start ,width end , height end )

	//These Functions can be Used Later if we Want to implement Functionalities like ZoomIn and ZoomOut

	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h); // Area on Screen to Display Objects ( width_start , height start ,width end , height end )
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
