#ifndef BALA_H
#define BALA_H


class Bala
{
public:
    int x;
    int y;
    Bala();
    Bala(int x, int y);

    void moverBal();
    bool fuera();
    int XB();
    int YB();
    void gotoxy(int x, int y);
};

#endif // BALA_H
