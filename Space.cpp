#include "iGraphics.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int mposx, mposy;
bool musicOn = true;
int x = 0;
int y = 0;
int dx = 10;
int dy = 10;
void iDraw()
{
	iClear();
	iSetColor(255, 0, 0);
	iFilledCircle(x, y, 10, 1000);

}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_UP)
	{
		y += 10;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		y -= 10;
	}
	
	else if (key == GLUT_KEY_RIGHT)
	{
		x += 10;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		x -= 10;
	}
	
	
	
}
void game(){
	x += dx;
	y += dy;
	if (x >= 600 || x <= 0)
		dx *= (-1);
	if (y >= 400 || y <= 0)
		dy *= (-1);
}

int main()
{
	iSetTimer(120, game);
	if (musicOn)
		PlaySound("\\play.wav", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(600, 400, "Space Strike");
	///updated see the documentations
	iStart();
	return 0;
}