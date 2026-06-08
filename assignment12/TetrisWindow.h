#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include <vector>

class TetrisWindow : public TDT4102::AnimationWindow {

private:
    int blockSizes = 30;
    int width = 15;
    int height = 22;
    TDT4102::Point startpunkt = {blockSizes*7,blockSizes};

    std::vector<std::vector<TetrominoType>> gridMatrix;
    Tetromino currentTetromino;

    void handleInput();

public:

    TetrisWindow();
    void run();
    void drawCurrentTetromino();

    void generateRandomTetromino();

    void moveTetrominoDown();

    void fastenTetromino();
    void drawGridMatrix();
};