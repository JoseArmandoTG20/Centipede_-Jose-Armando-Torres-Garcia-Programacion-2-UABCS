#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
#include <list>

#include "Nave.h"
#include "Bala.h"
#include "Hongos.h"
#include "Asteroid.h"


#define ARRIBA 119
#define IZQUIERDA 97
#define DERECHA 100
#define ABAJO 115
#define ESPACIO 32
#define Esc 27

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

using namespace std;

int menu(const char *opciones[], int n);

 void gotoxy(int x,int y)
 {
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

void ocultarCursor()
 {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hcon,&cci);
 }

void logo()
{
    printf("     ______ _______ ______  _______ _____ ______ _______ _____   _______   \n");
    printf("    / _____|_______)  ___ %c(_______|_____|_____ (_______|____ %c (_______)\n",92,92);
    printf("   | /      _____  | |   | |_         _   _____) )____   _   %c %c _____   \n",92,92);
    printf("   | |     |  ___) | |   | | |       | | |  ____/  ___) | |   | |  ___)    \n");
    printf("   | %c_____| |_____| |   | | |_____ _| |_| |    | |_____| |__/ /| |_____  \n",92);
    printf("    %c______)_______)_|   |_|%c______|_____)_|    |_______)_____/ |_______)\n",92,92);
    printf("\n");

}

void instrucciones()
{
    printf(" _____          _                       _                           \n");
    printf("|_   _|        | |                     (_)                          \n");
    printf("  | | _ __  ___| |_ _ __ _   _  ___ ___ _  ___  _ __   ___  ___      \n");
    printf("  | || '_ %c/ __| __| '__| | | |/ __/ __| |/ _ %c| '_ %c / _ %c/ __|  \n",92,92,92,92);
    printf(" _| || | | %c__ %c |_| |  | |_| | (_| (__| | (_) | | | |  __/%c__ %c   \n",92,92,92,92);
    printf(" %c___/_| |_|___/%c__|_|   %c__,_|%c___%c___|_|%c___/|_| |_|%c___||___/      \n",92,92,92,92,92,92,92);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("PUNTUACIONES: \n");
    printf("\n");
    printf("[A] Ara%ca: 50 puntos \n",164);
    printf("[%c] Hongo: 10 puntos \n",206);
    printf("Gusano (cuerpo): 10 puntos \n");
    printf("Gusano (cabeza): 100 puntos\n");
    printf("\n");
    printf("MOVIMIENTOS:\n");
    printf("\n");
    printf("[q] - Salir del Juego\n");
    printf("[w] - Moverse Arriba\n");
    printf("[s] - Moverse Abajo\n");
    printf("[a] - Moverse Derecha\n");
    printf("[d] - Moverse Izquierda\n");
    printf("[BARRA ESPACIO] - Disparar.\n");
}

void creditos()
{
    printf("     ___             _ _ _            \n");
    printf("    / __%c __ ___  __| (_) |_ ___  ___ \n",92);
    printf("   / / | '__/ _ %c/ _` | | __/ _ %c/ __|\n",92,92);
    printf("  / /__| | |  __/ (_| | | || (_) %c__ %c  \n",92,92);
    printf("  %c____/_|  %c___|%c__,_|_|%c__%c___/|___/ \n",92,92,92,92,92);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("  UNIVERSIDAD AUTONOMA DE BAJA CALIFORNIA SUR.\n");
    printf("\n");
    printf("  Programaci%cn II \n ",162);
    printf("\n");
    printf("  Profesor: Jonathan Soto Mu%coz. \n",164);
    printf("\n");
    printf("  Alumno: Jos%c Armando Torres Garcia.\n",130);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
}

void pintarLimites()
{
     for(int a = 2; a < 80; a++)
     {
         gotoxy(a,3); printf("%c",205);
         gotoxy(a,30); printf("%c",205);
     }

     for(int b = 4; b < 30; b++)
     {
         gotoxy(2,b); printf("%c",186);
         gotoxy(79,b); printf("%c",186);
     }

        gotoxy(2,3); printf("%c",201);
        gotoxy(2,30); printf("%c",200);
        gotoxy(79,3); printf("%c",187);
        gotoxy(79,30); printf("%c",188);
}

int main()
{
    ocultarCursor();

    bool juego = true;
    bool Game_Over = true;

    int puntos = 0;

    int op = 0;
    const char *opciones[] = {"JUGAR","INSTRUCCIONES","CREDITOS", "SALIR"};
    int n = 4;

    Nave nav(41,28,3,0);

    list<Asteroid*> As;
    list<Asteroid*>::iterator itA;

    for(int as = 0; as < 3; as++)
    {
        As.push_back(new Asteroid(4,4));
    }

    list<Hongos*> H;
    list<Hongos*>::iterator itH;

    //Generar Hongos
    for(int p = 0; p < 55; p++)
    {
        H.push_back(new Hongos(4 + rand() % 73, 5 + rand() % 23));
    }

    list<Bala*> B;
    list<Bala*>::iterator it;

    while (juego == true)
    {
        system("COLOR 02");

        op = menu(opciones,n);

        switch (op)
        {
            case 1:
                system("cls");

                Beep(330,125);
                Beep(392,125);
                Beep(330,250);
                Beep(440,125);
                Beep(0,125);

                Beep(440,125);
                Beep(494,125);
                Beep(523,250);
                Beep(523,125);
                Beep(0,125);

                Beep(523,125);
                Beep(587,125);
                Beep(494,250);
                Beep(494,125);
                Beep(0,125);

                pintarLimites();

                Game_Over = true;

                nav.vidas = 3;

                nav.sal = 0;

                while(Game_Over == true)
                {
                    nav.pintar();

                    nav.mover(Game_Over);

                    nav.morir();

                    gotoxy(64,2); printf("PUNTOS: %d",puntos);

                    gotoxy(37,2); printf("[CENTIPEDE]");

                    if(kbhit())
                    {
                        char tecla = getch();

                        //Generar Bala
                        if(tecla == ESPACIO)
                        {
                            B.push_back(new Bala(nav.XN()+1,nav.YN()));
                        }
                    }

                    if(nav.salir() == 1)
                    {
                        Game_Over = false;
                        puntos = 0;
                    }

                    if(nav.gameover() == 0)
                    {
                        gotoxy(37,15); printf("-[GAME OVER]-");
                        Sleep(400);
                        Game_Over = false;
                        puntos = 0;
                    }

                    //Disparo
                    for(it = B.begin(); it != B.end(); it++)
                    {
                        (*it)->moverBal();
                        if((*it)->fuera())
                        {
                            gotoxy((*it)->XB(),(*it)->YB()); printf(" ");
                            delete(*it);
                            it= B.erase(it);
                        }
                    }

                    //Pintar Hongos
                    for(itH = H.begin(); itH != H.end(); itH++)
                    {
                        (*itH)->Pintarhongos();
                    }

                    //Mover Asteroid
                    for(itA = As.begin(); itA != As.end(); itA++)
                    {
                        (*itA)->moverAs();
                        (*itA)->choqueAs(nav);
                    }

                    //Impacto Bala - Hongo
                    for(itH = H.begin(); itH != H.end(); itH++)
                    {
                        for(it = B.begin(); it != B.end(); it++)
                        {
                            if((*itH)->XH() == (*it)->XB() && ((*itH)->YH() == (*it)->YB()) /*|| ((*itH)->YH() == (*it)->YB())*/)
                            {
                                gotoxy((*it)->XB(),(*it)->YB()); printf(" ");
                                delete(*it);
                                it= B.erase(it);

                                gotoxy((*itH)->XH(),(*itH)->YH()); printf(" ");
                                delete(*itH);
                                itH= H.erase(itH);

                                puntos += 10;
                            }
                        }
                    }

                    //Impacto Bala - Asteroid
                    for(itA =As.begin(); itA != As.end(); itA++)
                    {
                        for(it = B.begin(); it != B.end(); it++)
                        {
                            if((*itA)->XA() == (*it)->XB() && ((*itA)->YA() + 1 == (*it)->YB()) || ((*itA)->YA() == (*it)->YB()))
                            {
                                gotoxy((*it)->XB(),(*it)->YB()); printf(" ");
                                delete(*it);
                                it= B.erase(it);

                                As.push_back(new Asteroid(rand() % 71 + 4,4));

                                gotoxy((*itA)->XA(),(*itA)->YA()); printf(" ");
                                delete(*itA);
                                itA= As.erase(itA);

                                puntos += 50;
                            }
                        }
                    }


                    Sleep(100);
                }
            break;

            case 2:
                system("cls");
                logo();
                instrucciones();
                cout << "Presione Enter para Regresar al Menu........" << endl;
                system("pause > null");
                Beep(330,125);
                Beep(392,125);
                Beep(330,250);
                Beep(440,125);
                Beep(0,125);
                system("cls");
            break;

            case 3:
                system("cls");
                logo();
                creditos();
                cout << "Presione Enter para Regresar al Menu........" << endl;
                system("pause > null");
                Beep(440,125);
                Beep(494,125);
                Beep(523,250);
                Beep(523,125);
                Beep(0,125);
                system("cls");
            break;

            case 4:
                Beep(349,250);
                Beep(500,500);
                Beep(349,350);
                Beep(440,125);
                Beep(800,700);
                Beep(523, 500);
                Beep(440, 375);
                Beep(523, 125);
                Beep(659, 650);

                Beep(349, 250);
                Beep(415, 500);
                Beep(349, 375);
                Beep(523, 125);
                Beep(440, 500);
                Beep(349, 375);
                Beep(523, 125);
                Beep(440, 650);

                system("cls");

                juego = false;
            break;
        }
    }
    return 0;
}


//Menu Principal
int menu(const char*opciones[],int n)
{
    int opcionSelecionada = 1;
    int tecla;
    bool repetir = true;
    do
    {
        system("cls");

        printf("\n");
        logo();
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");

        gotoxy(5,9 + opcionSelecionada); cout << "-->";

        for(int i = 0; i < n; i++)
        {
            gotoxy(10, 10 + i); cout << i + 1 << ".-" << opciones[i] << ".";
        }

        do
        {
            tecla = getch();
        }while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

        switch(tecla)
        {
            case TECLA_ARRIBA:
                opcionSelecionada --;

                if(opcionSelecionada < 1)
                {
                    opcionSelecionada = n;
                }
            break;

            case TECLA_ABAJO:
                opcionSelecionada ++;

                if(opcionSelecionada > n)
                {
                    opcionSelecionada = 1;
                }
            break;

            case ENTER:
                repetir = false;
            break;
        }

    }while(repetir);

    return opcionSelecionada;
}
