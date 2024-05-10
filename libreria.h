#define RESET_COLOR "\x1b[0m"
#define NEGRO_T "\x1b[30m"
#define NEGRO_F "\x1b[40m"
#define ROJO_T "\x1b[31m"
#define ROJO_F "\x1b[41m"
#define MAGENTA_T "\x1b[35m"
#define MAGENTA_F "\x1b[45m"
#define AMARILLO_T "\x1b[33m"
#define AMARILLO_F "\x1b[43m"
#define AZUL_T "\x1b[34m"
#define AZUL_F "\x1b[44m"
#define BLANCO_T "\x1b[37m"
#define BLANCO_F "\x1b[47m"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <unistd.h>

/* PROTOTIPOS */
int msges();
void menu();

void go_to_XY(int x, int y);
void text_to_XY(int x, int y, char *Texto);
void specialchar_to_XY(int x, int y, int Codigo);

void dibujar_titulo();
void dibujar_botones();
void dibujar_color(int cod);

void juego();
int aleat();

/* FUNCIONES */

void go_to_XY(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void text_to_XY(int x, int y, char *Texto)
{
    go_to_XY(x, y);
    printf("%s", Texto);
}

void specialchar_to_XY(int x, int y, int Codigo)
{
    go_to_XY(x, y);
    printf("%c", Codigo);
}

void dibujar_titulo()
{
    int title_length = strlen("SIMON DICE: JUEGO");
    int title_x = (50 - title_length) / 2;
    specialchar_to_XY(0, 0, 201);
    specialchar_to_XY(49, 0, 187);
    specialchar_to_XY(0, 4, 200);
    specialchar_to_XY(49, 4, 188);

    text_to_XY(title_x, 2, "SIMON DICE: JUEGO");

    for (int i = 0; i < 48; i++)
        specialchar_to_XY(i + 1, 0, 205);

    for (int i = 0; i < 3; i++)
    {
        specialchar_to_XY(0, i + 1, 186);
        specialchar_to_XY(49, i + 1, 186);
    }

    for (int i = 0; i < 48; i++)
        specialchar_to_XY(i + 1, 4, 205);

    printf("\n");
}

void dibujar_botones()
{
    // 8
    specialchar_to_XY(21, 9, 219);
    specialchar_to_XY(28, 9, 219);
    specialchar_to_XY(21, 10, 219);
    specialchar_to_XY(28, 10, 219);
    specialchar_to_XY(21, 11, 219);
    specialchar_to_XY(28, 11, 219);
    text_to_XY(24, 10, "8");

    // 4
    specialchar_to_XY(12, 13, 219);
    specialchar_to_XY(19, 13, 219);
    specialchar_to_XY(12, 14, 219);
    specialchar_to_XY(19, 14, 219);
    specialchar_to_XY(12, 15, 219);
    specialchar_to_XY(19, 15, 219);
    text_to_XY(15, 14, "4");

    // 6
    specialchar_to_XY(30, 13, 219);
    specialchar_to_XY(37, 13, 219);
    specialchar_to_XY(30, 14, 219);
    specialchar_to_XY(37, 14, 219);
    specialchar_to_XY(30, 15, 219);
    specialchar_to_XY(37, 15, 219);
    text_to_XY(33, 14, "6");

    // 2
    specialchar_to_XY(21, 17, 219);
    specialchar_to_XY(28, 17, 219);
    specialchar_to_XY(21, 18, 219);
    specialchar_to_XY(28, 18, 219);
    specialchar_to_XY(21, 19, 219);
    specialchar_to_XY(28, 19, 219);
    text_to_XY(24, 18, "2");
}

void dibujar_color(int cod)
{
    switch (cod)
    {
    case 0:
        for (int i = 21; i <= 28; i++)
        {
            go_to_XY(i, 9);
            printf(NEGRO_F " " RESET_COLOR);
        }
        for (int i = 21; i <= 28; i++)
        {
            go_to_XY(i, 11);
            printf(NEGRO_F " " RESET_COLOR);
        }
        for (int i = 12; i <= 19; i++)
        {
            go_to_XY(i, 13);
            printf(NEGRO_F " " RESET_COLOR);
            go_to_XY(i, 15);
            printf(NEGRO_F " " RESET_COLOR);
        }
        for (int i = 30; i <= 37; i++)
        {
            go_to_XY(i, 13);
            printf(NEGRO_F " " RESET_COLOR);
            go_to_XY(i, 15);
            printf(NEGRO_F " " RESET_COLOR);
        }
        for (int i = 21; i <= 28; i++)
        {
            go_to_XY(i, 17);
            printf(NEGRO_F " " RESET_COLOR);
            go_to_XY(i, 19);
            printf(NEGRO_F " " RESET_COLOR);
        }
        break;
    case 8:
        for (int i = 21; i <= 28; i++)
        {
            go_to_XY(i, 9);
            printf(AZUL_F " " RESET_COLOR);
        }
        for (int i = 21; i <= 28; i++)
        {
            go_to_XY(i, 11);
            printf(AZUL_F " " RESET_COLOR);
        }
        break;
    case 4:
        for (int i = 12; i <= 19; i++)
        {
            go_to_XY(i, 13);
            printf(AMARILLO_F " " RESET_COLOR);
            go_to_XY(i, 15);
            printf(AMARILLO_F " " RESET_COLOR);
        }
        break;
    case 6:
        for (int i = 30; i <= 37; i++)
        {
            go_to_XY(i, 13);
            printf(ROJO_F " " RESET_COLOR);
            go_to_XY(i, 15);
            printf(ROJO_F " " RESET_COLOR);
        }
        break;
    case 2:
        for (int i = 21; i <= 28; i++)
        {
            go_to_XY(i, 17);
            printf(MAGENTA_F " " RESET_COLOR);
            go_to_XY(i, 19);
            printf(MAGENTA_F " " RESET_COLOR);
        }
        break;
    }
}

int msges()
{
    system("cls");
    int op;
    printf("\n");
    printf("   M  E   N   U \n");
    printf("1.- JUGAR \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    int op;

    op = msges();

    switch (op)
    {
    case 1:
        juego();
        break;
    }
}

void juego()
{
    system("cls");
    int aleatorio;
    int secuencia_original[100];
    int elementos_original = 0;
    int secuencia_usuario[100];
    int elementos_usuario = 0;
    int puntos = 0;
    int vida = 1;
    int secuencias_iguales = 1;

    dibujar_titulo();
    dibujar_botones();

    do
    {
        secuencia_original[elementos_original] = aleat();

        if (elementos_original > 0)
        {
            for (int i = 0; i < elementos_original; i++)
            {
                dibujar_color(secuencia_original[i]);
                sleep(1);
                dibujar_color(0);
            }
        }
        else
        {
            dibujar_color(secuencia_original[0]);
        }

        sleep(1);
        dibujar_botones();

        printf("\n\n\n\n");

        printf("\nINGRESA LA SECUENCIA ->: \n");

        for (int i = 0; i < elementos_original; i++)
        {
            scanf("%d", &secuencia_usuario[i]);
        }

        for (int i = 0; i < elementos_original; i++)
        {
            if (secuencia_usuario[i] != secuencia_original[i])
            {
                secuencias_iguales = 0;
                break;
            }
        }

        if (secuencias_iguales == 0)
        {
            vida = 0;
            printf("\n FIN DEL JUEGO \n");
        }
        else
        {
            elementos_usuario++;
            elementos_original++;
            puntos++;
        }
    } while (vida);

    printf("\n PUNTOS: %d\n\n", (puntos-1));
    system("pause");
}

int aleat()
{
    int permitidos[4] = {8, 4, 6, 2};
    int aleatorio = rand() % 4;
    return permitidos[aleatorio];
}