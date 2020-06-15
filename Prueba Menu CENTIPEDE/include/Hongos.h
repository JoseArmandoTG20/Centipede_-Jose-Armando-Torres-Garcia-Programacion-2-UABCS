#ifndef HONGOS_H
#define HONGOS_H


class Hongos
{
    public:
        int x;
        int y;
        int numx;
        int numy;

        Hongos();
        Hongos(int x, int y);


        void Pintarhongos();
        void gotoxy(int x, int y);
        void impactohongo(struct Nave &Naves);
        int XH();
        int YH();

    private:
};

#endif // HONGOS_H
