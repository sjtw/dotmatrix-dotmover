#include "DotMover.h"

DotMover d = DotMover(0, 0);

void setup()
{
    Serial.begin(9600);
    Serial.println("ok");
}

bool right = true;
bool up = true;

void loop()
{
    Serial.println("loop");
    d.Render();
    if (d.GetX() == 7)
        right = false;
    if (d.GetX() == 1)
        right = true;
    if (d.GetY() == 7)
        up = false;
    if (d.GetY() == 1)
        up = true;

    if (right)
        d.Right(1);
    else
        d.Left(1);
    d.Render();
    wait();

    if (up)
        d.Up(1);
    else
        d.Down(1);
    d.Render();
    wait();
}
