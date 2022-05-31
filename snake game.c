#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
int i, j, visina = 20, duzina = 20, poeni=0, gameover; 
int x, y, vocex, vocey, kretanje;

void main_menu() 
{
	system("cls");
	int odl;
	P:
	printf("SNAKE GAME \n");
	printf(" \n");
	printf("1. igraj \n");
	printf("2. izadji iz igre \n");
	scanf("%d", &odl);
	switch (odl)
		{
			case 1:
				gameover = 0;
				break;
			case 2:
				gameover = 1;
				break;
			default:
				printf("nevazeca komanda \n");
				goto P;
				break;
		}
	
}

/*void main_menu v2() 
{
	system("cls");
	int odl;
	P:
	printf("SNAKE GAME \n");
	printf(" \n");
	printf("1. igraj \n");
	printf("2. izadji iz igre \n");
	scanf("%d", &odl);
	switch (odl)
		{
			case 1:
				printf("Izaberi tezinu: \n");
				printf(" ");
				printf("1. easy");
				printf("2. normal");
				printf("3. hard");
			case 2:
				gameover = 1;
				break;
			default:
				printf("nevazeca komanda \n");
				goto P;
				break;
		}
	
}*/

void setup()
{
	gameover = 0;
	x = duzina/2;
	y = visina/2;
	label1:
		vocex = rand()%20;
		if (vocex == 0)
		{
			goto label2;
		}
	label2:
		vocey = rand()%20;
		if (vocey == 0)
		{
			goto label1;
		}
	poeni=0;
}

void crtanje () 
{
	system("cls");
	for ( i = 0; i < visina; i++)
	{
		for ( j = 0; j < duzina; j++)
		{
			if ( i == 0 || i == duzina - 1 || j == 0 || j == visina - 1)
			{
				printf("#");
			}
			else if ( i == y && j == x)
			{
				printf("0");
			}
			else if ( i == vocey && j == vocex )
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	printf("poeni: %d \n", poeni);
	printf("pretisni X da izadjes iz igrice \n");
	
}

void kontrole()
{
	if (kbhit())
	{
		switch(getch())
		{
		case 'w':
            kretanje = 1;
            break;
        case 'a':
            kretanje = 2;
            break;
        case 's':
            kretanje = 3;
            break;
        case 'd':
            kretanje = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
	}
}

void funkcionisanje()
{
	float sleep_interval;
	ponovo:
	sleep_interval=1.5-1.0*poeni/100;
	sleep(sleep_interval);
	switch(kretanje)
	{
	case 1:
        y--;
        break;
    case 2:
        x--;
        break;
    case 3:
        y++;
        break;
    case 4:
        x++;
        break;
    default:
        break;
    }
	if (x < 0 || x > duzina || y < 0 || y > visina)
	{
		gameover=1;
	}
	srand((unsigned)time(0));
	if (x == vocex && y == vocey)
	{
		label3:
			vocex=rand()%20;
			if (vocex == 0)
			{
				goto label3;
			}
		label4:
			vocey=rand()%20;
			if (vocey == 0)
			{
				goto label4;
			}
			poeni+=10;
			goto ponovo;
	}
}


void main() 
{
	setup();
	int m, n;
	setup();
	main_menu();
	while (!gameover)
	{
		crtanje();
		kontrole();
		funkcionisanje();
	}
}
