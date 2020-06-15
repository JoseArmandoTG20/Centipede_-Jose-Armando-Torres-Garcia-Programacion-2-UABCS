#ifndef NAVE_H
#define NAVE_H


class Nave
{
    public:
        int x;
        int y;
        int sal;
        int vidas;

        Nave();
        Nave(int x, int y,int vidas, int sal);

        void pintar();
        void borrar();
        void mover(bool Game_Over);
        void pintarvidas();
        int salir();
        int punt();
        int gameover();
        void morir();
        void Vid();
        int XN();
        int YN();
        void gotoxy(int x,int y);
    private:
};

#endif // NAVE_H
