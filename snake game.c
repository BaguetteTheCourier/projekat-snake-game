#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

int i, j, visina = 20, duzina = 20, poeni=0, gameover; 
int x, y, vocex, vocey, kretanje;

int main_menu() //nece da radi main menu kako treba za sad
{
	system("cls");
	char odl;
	printf("SNAKE GAME \n");
	printf(" \n");
	printf("pretisni P da igras \n");
	printf("pretisni E da izadjes iz igre \n");
	scanf("%c", &odl);
	if ('p' == odl)
	{
		gameover=0;
		return 1;
	}
	else if ('e' == odl)
	{
		gameover=1;
		return 0;
	}
	
}

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
	sleep(0.9);
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
	}
}


void main() {
	int m, n;
	setup();
	while (!gameover)
	{
		main_menu();
		crtanje();
		kontrole();
		funkcionisanje();
	}
}
