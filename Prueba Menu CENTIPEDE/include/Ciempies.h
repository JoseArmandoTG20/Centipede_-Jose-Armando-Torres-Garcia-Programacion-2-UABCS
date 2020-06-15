#ifndef CIEMPIES_H
#define CIEMPIES_H


class Ciempies
{
    public:
        int x;
        int y;
        int numx;
        int numy;
        Ciempies();
        Ciempies(int x, int y);

        void gotoxy(int x, int y);
        int XC();
        int YC();
        void pintarciem();
        void moverciem();
        void borrarciem();

};

#endif // CIEMPIES_H
