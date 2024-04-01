#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define MAGENTA_T        "\x1b[35m"
#define MAGENTA_F        "\x1b[45m"
#define AMARILLO_T "\x1b[33m"
#define    AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define    AZUL_F      "\x1b[44m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <unistd.h>

/* PROTOTYPES */
int msges();
void menu();

void go_to_XY(int x, int y);
void text_to_XY(int x, int y, char *Text);
void specialchar_to_XY(int x, int y, int Code);

void draw_title();
void draw_wasd();
void draw_color(int letter_code);

void cls();

void gameover(int status);
void play(int vector[], int points);
void heart();



/* FUNCTIONS*/

 /////////////////////////////
/////// GO TO'S FUNCTIOS //////////
  //////////////////////////////

void go_to_XY(int x, int y) 
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void text_to_XY(int x, int y, char *Text) 
{
    go_to_XY(x, y);
    printf("%s", Text);
}

void specialchar_to_XY(int x, int y, int Code) 
{
    go_to_XY(x, y);
    printf("%c", Code);
}


   /////////////////////////////
/////// DRAW FUNCTIONS //////////
  //////////////////////////////

void draw_title() 
{
    int title_length = strlen("SIMON DICE: JUEGO");
    int title_x = (50 - title_length) / 2; 
    specialchar_to_XY(0, 0, 201);
    specialchar_to_XY(49, 0, 187); 
    specialchar_to_XY(0, 4, 200);
    specialchar_to_XY(49, 4, 188); 

    text_to_XY(title_x, 2, "SIMON DICE: JUEGO");
    
    for(int i = 0; i < 48; i++) 
        specialchar_to_XY(i + 1, 0, 205);

    for(int i = 0; i < 3; i++) {
        specialchar_to_XY(0, i + 1, 186);
        specialchar_to_XY(49, i + 1, 186); 
    }

    for(int i = 0; i < 48; i++) 
        specialchar_to_XY(i + 1, 4, 205);

    printf("\n");
}

void draw_wasd() {
    // w
    specialchar_to_XY(21, 6, 219);
    specialchar_to_XY(28, 6, 219);

    specialchar_to_XY(21, 7, 219);
    specialchar_to_XY(28, 7, 219);

    specialchar_to_XY(21, 8, 219);
    specialchar_to_XY(28, 8, 219);

    text_to_XY(24, 7, "W");

    // a
    specialchar_to_XY(12, 10, 219);
    specialchar_to_XY(19, 10, 219);
    specialchar_to_XY(12, 11, 219);
    specialchar_to_XY(19, 11, 219);
    specialchar_to_XY(12, 12, 219);
    specialchar_to_XY(19, 12, 219);
    text_to_XY(15, 11, "A");

    // s
    specialchar_to_XY(21, 10, 219);
    specialchar_to_XY(28, 10, 219);
    specialchar_to_XY(21, 11, 219);
    specialchar_to_XY(28, 11, 219);
    specialchar_to_XY(21, 12, 219);
    specialchar_to_XY(28, 12, 219);
    text_to_XY(24, 11, "S");

    // d
    specialchar_to_XY(30, 10, 219);
    specialchar_to_XY(37, 10, 219);
    specialchar_to_XY(30, 11, 219);
    specialchar_to_XY(37, 11, 219);
    specialchar_to_XY(30, 12, 219);
    specialchar_to_XY(37, 12, 219);
    text_to_XY(33, 11, "D");
}


void draw_color(int letter_code) {
    
    char letter;

    switch(letter_code)
    {
        case 0: //w
            for(int i = 22; i < 28; i++)
            {
                go_to_XY(i, 6);
                printf(AMARILLO_F " " RESET_COLOR);
            }

            for(int i = 22; i < 28; i++)
            {
                go_to_XY(i, 8);
                printf(AMARILLO_F " " RESET_COLOR);
            }      
        break;

        case 1: //a
            for(int i = 13; i < 19; i++)
            {
                go_to_XY(i, 10);
                printf(ROJO_F " " RESET_COLOR);
            }

            for(int i = 13; i < 19; i++)
            {
                go_to_XY(i, 12);
                printf(ROJO_F " " RESET_COLOR);
            }      
        break;

        case 2: //s
            for(int i = 22; i < 28; i++)
            {
                go_to_XY(i, 10);
                printf(AZUL_F " " RESET_COLOR);
            }

            for(int i = 22; i < 28; i++)
            {
                go_to_XY(i, 12);
                printf(AZUL_F " " RESET_COLOR);
            } 
        break;

        case 3: //d
            for(int i = 31; i < 37; i++)
            {
                go_to_XY(i, 10);
                printf(MAGENTA_F " " RESET_COLOR);
            }

            for(int i = 31; i < 37; i++)
            {
                go_to_XY(i, 12);
                printf(MAGENTA_F " " RESET_COLOR);
            } 
        break;
    }

    draw_wasd();

   
}



   /////////////////////////////
/////// GAME FUNCTIONS //////////
  //////////////////////////////



//****************
int msges()
{ int op;
  printf("\n");
  printf ("   M  E   N   U \n");
  printf("1.- JUGAR \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}


//****************
void menu()
{
    int vector[] = {};
    int points;
    int op;

    op=msges();
    
    switch (op)
    {
        case 0:
        gameover(0);
              break;
        
        case 1:
        play(vector, points);
              break;
    }

}


/***************************************/
void gameover(int status)
{
    switch(status)
    {
        case 0:
            printf("\n GAMEOVER. \n");
        break;
    }
}


/***************************************/

void cls()
{
    system("cls");
}


/***************************************/

void pause()
{
    system("pause");
}


/***************************************/

void play(int vector[], int points)
{
    int bandera = 1;
    int aleatorio;
    int i = 0;
    char ch;

    cls();
    draw_title();
    draw_wasd();
    printf("\n\n\n");

    do
    {
        aleatorio = rand() % 4;
        sleep(1);
        draw_color(aleatorio);
        vector[i] = aleatorio;
        i++;

        for(int j = i; j <= 0; j--)
        {
            printf("\n\n\n\n\n\n\n Introduce el orden:");
            fflush(stdin);
            gets(ch);
        }


    }while(bandera);

    printf("\n\n\n\n\n\n");

}


