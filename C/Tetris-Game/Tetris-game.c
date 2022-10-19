/* 
	Game: Console Tetris
	Coded by: UtkarshSiddhpura
	NOTE: Below game only works in "Turbo C" as it uses Header files 
		  exclusive to Turbo C.
			- You can use https://www.onlinegdb.com/ with TurboC compiler to test.
			  (it might be laggy as it runs in browser)	
	Move : 1, 2, 3 and 0. 
	Exit : Hit Esc.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

void update();
void delayAndKeyHandler();
void handleRotateCollision();
void manageX();

void drawArena();
void arenaSweep();
int collision();

int getRandomTetri();
void putTetri(int undo);
void rotateTetri();
void resetTetri();

void gameOver();

int main()
{
	resetTetri();
	update();
	return 0;
}

int key;
int score = 0;
int arena[24][14] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}};

int x, y; // x and y position of Current moving tetri
int noOfTetri;
int tetris[7][4][4] = {
	{{0, 3, 0},
	 {0, 3, 0},
	 {3, 3, 0}},
	{{0, 3, 0, 0},
	 {0, 3, 0, 0},
	 {0, 3, 0, 0},
	 {0, 3, 0, 0}},
	{{0, 0, 0},
	 {3, 3, 0},
	 {0, 3, 3}},
	{{0, 3, 0},
	 {0, 3, 0},
	 {0, 3, 3}},
	{{0, 0, 0},
	 {0, 3, 3},
	 {0, 3, 3}},
	{{0, 0, 0},
	 {0, 3, 3},
	 {3, 3, 0}},
	{{0, 0, 0},
	 {3, 3, 3},
	 {0, 3, 0}}};

void delayAndKeyHandler(int ms)
{
	while(ms < 200){
		delay(2);
		if (kbhit())
		{
			key = getch();
			if (key == 49)
			{
				putTetri(1);//undoing the prev change
				x--;
				manageX(-1);
				clrscr();
				putTetri(-1);
				drawArena();
				putTetri(1);
			} else if (key == 50)
			{
				putTetri(1);
				y++;
				if (collision())
				{
					if (y == 1)
					{
					      gameOver();
					}
					y--;	      //as collision so to put the tetri on previous position
					putTetri(-1); //put it again
					arenaSweep();
					resetTetri();
				}
				clrscr();
				putTetri(-1);
				drawArena();
				putTetri(1);

			}
			else if (key == 51)
			{
				putTetri(1);
				x++;
				manageX(+1);
				clrscr();
				putTetri(-1);
				drawArena();
				putTetri(1);
			}
			else if (key == 48)
			{
				putTetri(1);
				rotateTetri();
				handleRotateCollision();
				clrscr();
				putTetri(-1);
				drawArena();
				putTetri(1);
			}
			else if (key == 27)
			{
				exit(0);
			}
		}ms++;
	}
}
void handleRotateCollision()
{
	int dir = 1;
	while (collision())
	{
		x += dir;
		dir++;
		dir *= -1;
	}
}
void manageX(int dir)
{ // manages X pos of current Tetri
	int index = collision();
	if (index)
	{
		x = x - dir;
	}
}
void drawArena()
{
	int i, j;
	printf("Move Using-1,2,3,0 | Score: %d", score);
	for (i = 0; i < 24; i++)
	{
		for ( j = 0; j < 14; j++)
		{
			if (i == 23)
			{
				printf("\"\"");
			}
			else if (arena[i][j] == 1)
			{
				printf("||");
			}
			else if (arena[i][j] == 0)
			{
				printf("  ");
			}
			else if (arena[i][j] == 3)
			{
				printf("[]");
			}
		}
		printf("\n");
	}
}
void arenaSweep() 
{
	int i, j, p, q;
	int boolean = 0;
	for ( i = 22; i > 0; i--)
	{
		boolean = 0;
		for ( j = 1; j < 13; j++)
		{
			if (arena[i][j] != 3)
			{
				boolean = 1;
				break;
			}
		}
		if (boolean)
			continue;
		for ( p = i; p > 0; p--)
		{
			for ( q = 1; q < 13; q++)
			{
				arena[p][q] = arena[p - 1][q];
			}
		}
		i++;
		score += 175;
	}
}
// checking all collision and returing 0 or
int collision()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			if (arena[y + i][x + j] != 0)
			{
				if (tetris[noOfTetri][i][j] != 0)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int getRandomTetri()
{
	time_t t;
	srand((unsigned)time(&t));
	return rand() % 7;
}
// y -> 0-22, x-> 0-8
void putTetri(int undo)
{
	int i, j;
	int n = noOfTetri == 1 ? 4 : 3;
	for ( i = y; i < y + n; i++)
	{
		for ( j = x; j < x + n; j++)
		{
			if (tetris[noOfTetri][i - y][j - x] == 3)
			{
				if (undo == 1)
				{
					arena[i][j] = 0;
				}
				else
				{
					arena[i][j] = tetris[noOfTetri][i - y][j - x];
				}
			}
		}
	}
}
void rotateTetri()
{
	int i, j, n;
	int arr[4][4];
	n = noOfTetri == 1 ? 4:3;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr[i][j] = tetris[noOfTetri][j][i];
		}
	}
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			tetris[noOfTetri][n - i - 1][j] = arr[i][j];
		}
	}
}
void resetTetri()
{
	x = 3;
	y = 0;
	noOfTetri = getRandomTetri();
}
void gameOver()
{
	printf(" ::::: GAME OVER :::: \n");
	printf(" :: Press Any Key to Exit ::");
	getch();
	exit(0);
}
void update()
{
	y++;
	if (collision())
	{
		if (y == 1)
		{
			gameOver();
		}
		y--;		  //so to put the tetri on previous position
		putTetri(-1); //put it again
		arenaSweep();
		resetTetri();
	}
	putTetri(-1); // -1 mean putting tetri
	clrscr();
	drawArena();
	delayAndKeyHandler(2);
	putTetri(1); // 1 means undo removing tetri
	update();
}