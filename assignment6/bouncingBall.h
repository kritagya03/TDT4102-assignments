#pragma once
#include "Color.h"
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

struct Config{
    int ColorUp;
    int ColorDown;
    int BallSpeed;
};

const  map <int, Color> aColor{
        {1, Color::blue},
        {2, Color::green},
        {3, Color::pink},
        {4, Color::brown}
    };

istream& operator>>(istream& is, Config& cfg);

void bouncingBall();