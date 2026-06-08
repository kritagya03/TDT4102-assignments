#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji{
protected:
    Point centre;
    int radius;
public:
    Face(Point c, int r);
    virtual void draw(AnimationWindow& win) override =0;
};

class EmptyFace  : public Face{
protected:
    Point eyeOne;
    Point eyeTwo;
    int eyeRadius;
public:
    EmptyFace(Point c, int r, Point eye, int r2);
    virtual void draw(AnimationWindow& win) override;
};

class SmilingFace : public EmptyFace{
protected:
    Point centerPoint;
    int width;
    int height;
    int startDegree;
    int endDegree;
public:
    SmilingFace(Point c, int r, Point eye, int r2,
    int sd, int ed);
    virtual void draw(AnimationWindow& win) override;
};

class SadFace : public EmptyFace{
protected:
    Point centerPoint;
    int width;
    int height;
    int startDegree;
    int endDegree;
public:
    SadFace(Point c, int r, Point eye, int r2,
    int sd, int ed);
    virtual void draw(AnimationWindow& win) override;
};