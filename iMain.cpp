#include "iGraphics.h"
#include<math.h>
#include<string.h>

int shoot = 0, explode = 0, colcount = 100; 
struct health{
	int health_x = 0;
	int health_y = 574;
	int h_xsize = 160;
	int h_ysize = 40;
	int h_red = 255;
	int h_green = 0;
	int h_blue = 0;
	int const healthsize = 160;
};
struct health lifeline;

struct gamescore{
	int score=0;
	int score_x = 960;
	int score_y = 580;
	char scorestring[10];
};
struct gamescore playerscore;

struct menu{
	int i;
}menu;

int end1, en1=0 ,en2=0;
int b,r,back,cov,jho;
int w,score1,score2,sh,mo,mi,ma,me,mu;
int i = 0;
int mpx, mpy;
int score;
int x = 0;
int y = 0;
int p = 0, q = 0;
int e, f;
int c = 1024;
double d = 50;
int c1 = 1024;
double d1 = 20;
int c2 = 1024;
double d2 = 100;
int c3 = 1024;
double d3 = 300;
int c4 = 1024;
double d4 = 200;
double m1 = 1024;
double m2 = 220;
double m3 = 1024;
double m4 = 75;
double m5 = 1024;
double m6 = 340;
double m7 = 1024;
double m8 = 450;
double m9 = 1024;
double m10 = 400;
bool musicOn = true;

void ShowHealth(){

	if (lifeline.h_xsize > 0){
		if (lifeline.h_xsize >= lifeline.healthsize / 2)
		{
			lifeline.h_blue = 0; lifeline.h_red = 255, lifeline.h_green = 0;
		}
		else if (lifeline.h_xsize <  lifeline.healthsize / 2 &&
			lifeline.h_xsize >= lifeline.healthsize / 4){
			lifeline.h_blue = 17; lifeline.h_red = 255, lifeline.h_green = 251;
		}
		else{
			lifeline.h_blue = 0; lifeline.h_red= 0, lifeline.h_green = 255;
		}

		iSetColor(lifeline.h_green, lifeline.h_red, lifeline.h_blue);
		iFilledRectangle(lifeline.health_x, lifeline.health_y, lifeline.h_xsize,
			lifeline.h_ysize);
	}
}
void ShowScore(){
	_itoa_s(playerscore.score, playerscore.scorestring, 10);
	iSetColor(0, 255, 0);
	iText(playerscore.score_x, playerscore.score_y, playerscore.scorestring, GLUT_BITMAP_TIMES_ROMAN_24);
}

void iDraw()
{
	iClear();

	if (menu.i == 0)
	{ 
		iShowImage(0, 0, 1024, 615, cov);
		iText(260, 100, "CLICK ON THE SPACESHIP TO CONTINUE...", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (menu.i == 1){
		iShowImage(0, 0, 640, 640, b);
		iText(10, 30, "Our planet is no longer habitable. So we're heading towards a new planet. We have to kill enemies on the way.", GLUT_BITMAP_9_BY_15);

		iShowImage(680, 440, 280, 110, score1);
		iShowBMP2(630, 220, "14.bmp", 0);
		iShowImage(750, 60, 150, 150, score2);
	}
	if (menu.i == 2){
		iShowImage(0, 0, 1024, 615, back);
		iShowImage(p, q, 200, 200, sh); 
		ShowScore();
		ShowHealth();
		if (shoot == 1)
		{
			if (explode == 0)
			{
				//laser
				iShowImage(e, f, 150, 50, w);
				e +=7;
			}

			if (e==c  || e==c1 || e==c2 || e==c3 || e==c4 || e==m1 || e==m3 || e==m5 || e==m7  || e==m9  && colcount>0)
			
			{
				explode = 1;
				//explosion
				iShowImage(e, f, 80, 80, jho);
				d -= 1;
				d1 -= 0.5;
				d2 -= 0.1;
				d3 -= 0.01;
				d4 -= 0.04;
				
				m2 -= 0.12;
				
				m4 -= 0.09;
				
				m6 -= 0.045;
				
				m8 -= 0.087;
			
				m10 -= .2;
				
				colcount -= 1;
				
				if (colcount == 0)
				{
					playerscore.score++;
					lifeline.h_xsize= lifeline.h_xsize-4;
					colcount = 100;
					shoot = 0;
				}
				
				}
		
		}
		iSetColor(255, 255, 255);
		
		iShowImage(c, d, 150, 100, r);
		iShowImage(c1, d1, 150, 100, r);
		iShowImage(c2, d2, 150, 100, r);
		iShowImage(c3, d3, 150, 100, r);
		iShowImage(c4, d4, 150, 100, r);
		iShowImage(m1, m2, 150, 100, mi);
		iShowImage(m3, m4, 100, 100, mo);
		iShowImage(m5, m6, 100, 100, me);
		iShowImage(m7, m8, 100, 100, ma);
		iShowImage(m9, m10, 150, 150, mu);
		iSetColor(0, 200, 0);
		iText(850, 580, "SCORE : ", GLUT_BITMAP_TIMES_ROMAN_24);
		
		if (lifeline.h_xsize <= 0){
			
			iShowImage(en1, en2, 1024, 615, end1);

		}
		
}
	
	if (menu.i == 3)
	{
		iShowImage(0, 0, 1024, 615, score);
	}
}

void iMouseMove(int mx, int my)
{

}

void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	printf("%d %d\n", mx, my);
	if (menu.i == 0)
	{
		if (mx >= 508 && mx <= 667 && my >= 244 && my <= 284)
		{
			menu.i++;
		}
	}
	printf("%d %d\n", mx, my);
	if (menu.i == 1)
	{
		if (mx >= 702 && mx <= 952 && my >= 474 && my <= 565)
		{ 
			menu.i++;
		}
	}
	printf("%d %d\n", mx, my);
	if (menu.i == 1)
	{
		if (mx >= 712 && mx <= 973 && my >= 288 && my <= 364)
		{
			exit(0);
		}
	}
	printf("%d %d\n", mx, my);
	if (menu.i == 1)
	{
		if (mx >= 699 && mx <= 988 && my >= 86 && my <= 180)
		{
			menu.i=menu.i+2;
		}
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{


	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void iKeyboard(unsigned char key)
{
	if (key == 'u')
	{
		q = q + 10;
	}
	else if (key == 'd')
	{
	
		q = q - 10;
		
	}
	else if (key == 'r')
	{
		p = p + 10;
		
	}
	else if (key == 'l')
	{
		p = p - 10;
		
	}
}


void iSpecialKeyboard(unsigned char key)
{

	 if (key == GLUT_KEY_HOME)
	{
		 e = 175 + p;
		 f = 75 + q;
		 shoot = 1;
		 explode = 0;
	}
	if (key == GLUT_KEY_F2)
	{
		
	}
	if (key == GLUT_KEY_RIGHT)
	{
		
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}



}
void obstacles1(){

	c = c - 10;
	
}
void obstacles2(){


	c1 = c1 - 14;
	
	
}
void obstacles3(){


	c2 = c2 - 13;
	
	
}
void obstacles4(){


	c3 = c3 - 10;
	
	
}
void obstacles5(){


	c4 = c4 - 11;

}
void mon1(){


	m1 = m1 - 20;

	
}
void mon2(){


	m3 = m3 - 25;

	
}
void mon3(){


	m5 = m5 - 22;

	
}
void mon4(){


	m7 = m7 - 23;

}
void mon5(){


	m9 = m9 - 21;

}


int main()
{
	
	iSetTimer(350, obstacles1);
	iSetTimer(2200, obstacles2);
	iSetTimer(500, obstacles3);
	iSetTimer(750, obstacles4);
	iSetTimer(900, obstacles5);
	iSetTimer(620, mon1);
	iSetTimer(3200, mon2);
	iSetTimer(800, mon3);
	iSetTimer(1200, mon4);
	iSetTimer(1500, mon5);

	if (musicOn)
		PlaySound("song.wav", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(1024,615, "Space Strike");
	back = iLoadImage("glax.jpg");
	cov = iLoadImage("cover.jpg");
	b = iLoadImage("pri.bmp");
	score1 = iLoadImage("11a.jpg");
	score2 = iLoadImage("bla.jpg");
	r = iLoadImage("o1.png");
	w = iLoadImage("laser.png");
	sh = iLoadImage("rock1.png");
	mo = iLoadImage("mo1.png");
	mi = iLoadImage("mo2.png");
	me = iLoadImage("mo4.png");
	ma = iLoadImage("aa.png");
	mu = iLoadImage("mo5.png");
	score = iLoadImage("mark31.jpg");
	jho = iLoadImage("jha.png");
	end1 = iLoadImage("ended.jpg");
	iStart();
	return 0;
}