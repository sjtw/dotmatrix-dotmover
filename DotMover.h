#include <LedControl.h>
#ifndef DotMover_h
#define DotMover_h

class DotMover
{

private:
    int _x;
    int _y;
    int ADDR;
    LedControl lc;

public:
    void Left(int amount);
    void Right(int amount);
    void Up(int amount);
    void Down(int amount);
    void Render();
    void Log();
    // struct Dot GetCoords();
    int GetX();
    int GetY();
    DotMover(int, int);
    ~DotMover();
};

#endif