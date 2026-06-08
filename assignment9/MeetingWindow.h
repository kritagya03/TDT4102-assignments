#pragma once
#include <iostream>
#include "Person.h"
#include <vector>
#include <memory>
#include "AnimationWindow.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"

class MeetingWindow : public TDT4102::AnimationWindow{
private:
    static constexpr int pad=50;
    static constexpr int btnW=pad*2;
    static constexpr int btnH=pad;
    static constexpr int fieldW=pad*10;
    static constexpr int fieldH=pad;

    std::vector<std::shared_ptr<Person>> people;

    TDT4102::Button quitBtn{{900,20}, btnW, btnH, "Quit"};
    TDT4102::TextInput personName{{pad,20},fieldW,fieldH,"Person name"};
    TDT4102::TextInput personEmail{{pad,20+pad},fieldW,fieldH,"Person email"};
    TDT4102::Button personNewBtn {{pad,20+2*pad},btnW, btnH,"Add"};
public:
    MeetingWindow(int x, int y, int w, int h, const std::string& title);
    void addd();

    void cb_quit();
    void cb_personName();
};