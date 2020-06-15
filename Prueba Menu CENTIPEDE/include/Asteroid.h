#ifndef ASTEROID_H
#define ASTEROID_H

#include "Nave.h"

class Asteroid
{
    public:
        int x;
        int y;

        //Nave nave;
        Asteroid();
        Asteroid(int x, int y);

        int XA();
        int YA();

        void pintarAs();
        void moverAs();
        void borrarAs();
        void choqueAs(struct Nave &nav);
        void gotoxy(int x,int y);
};

#endif // ASTEROID_H
