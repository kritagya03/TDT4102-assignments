#include "Emoji.h"
#include "std_lib_facilities.h"
#include "AnimationWindow.h"


Face::Face(Point c, int r){
    centre=c;
    radius=r;
}

void Face::draw(AnimationWindow& win){
    win.draw_circle(centre, radius, Color::yellow);
}

EmptyFace::EmptyFace(Point c, int r, Point eye, int r2): Face(c,r){
    int x_movement=centre.x;
    int y_movement=centre.y;

    eyeOne={x_movement-eye.x,y_movement-eye.y};
    eyeTwo={x_movement+eye.x,y_movement-eye.y};
    eyeRadius=r2;
}

void EmptyFace::draw(AnimationWindow& win){
    Face::draw(win);
    win.draw_circle(eyeOne,eyeRadius,Color::black);
    win.draw_circle(eyeTwo,eyeRadius,Color::black);
}

SmilingFace::SmilingFace(Point c, int r, Point eye, int r2,
int sd, int ed): EmptyFace(c,r,eye,r2) {
    centerPoint=c;
    width=r/2;
    height=r/2;
    startDegree=sd;
    endDegree=ed;
}

void SmilingFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(centerPoint, width, height, startDegree, endDegree);
}

SadFace::SadFace(Point c, int r, Point eye, int r2,
int sd, int ed): EmptyFace(c,r,eye,r2) {
    centerPoint={c.x,c.y+3/2*r};
    width=r/2;
    height=r/2;
    startDegree=sd;
    endDegree=ed;
}

void SadFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(centerPoint, width, height, startDegree, endDegree);
}