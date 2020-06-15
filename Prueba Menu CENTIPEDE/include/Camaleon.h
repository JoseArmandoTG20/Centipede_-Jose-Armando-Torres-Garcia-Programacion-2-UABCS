#ifndef CAMALEON_H
#define CAMALEON_H


class Camaleon
{
    public:
        int x;
        int y;

        Camaleon();
        Camaleon(int x, int y);

        void gotoxy(int x,int y);
        void pintarCam();
        void moverCam();

        int XCa();
        int YCa();

};

#endif // CAMALEON_H
