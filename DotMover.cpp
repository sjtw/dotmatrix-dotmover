#include "DotMover.h"

int countBitShifts(int n)
{
    int i = 0;
    while (n > 1)
    {
        i++;
        n >>= 1;
    }

    return i;
}

DotMover::DotMover(int x, int y)
    : lc(12, 10, 11, 1)
{
    ADDR = 0;
    lc.shutdown(ADDR, false);
    lc.setIntensity(ADDR, 8);
    lc.clearDisplay(ADDR);
    if (x == 0)
        _x = 1;
    else
        _x = 1 << x;
    _y = y;
    Render();
};

DotMover::~DotMover()
{
}

void DotMover::Left(int amount = 1)
{
    _x = _x >> amount;
    Render();
}

void DotMover::Right(int amount = 1)
{
    if (_x == 0)
        _x = 1;
    else
        _x = _x << amount;
    Render();
}

void DotMover::Up(int amount = 1)
{
    _y = _y + amount;
    Render();
}

void DotMover::Down(int amount = 1)
{
    _y = _y - amount;
    Render();
}

int DotMover::GetX()
{
    return countBitShifts(_x);
}

int DotMover::GetY()
{
    return _y;
}

void DotMover::Render()
{
    lc.clearDisplay(ADDR);
    lc.setRow(ADDR, _y, _x);
}