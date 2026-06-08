#include "TetrisWindow.h"
#include "Tetromino.h"
#include <iostream>
#include <random>
#include <map>

const std::map<TetrominoType, TDT4102::Color> toColor{
    {TetrominoType::J, TDT4102::Color::dark_blue},
    {TetrominoType::L, TDT4102::Color::orange},
    {TetrominoType::I, TDT4102::Color::turquoise},
    {TetrominoType::O, TDT4102::Color::yellow},
    {TetrominoType::S, TDT4102::Color::green},
    {TetrominoType::T, TDT4102::Color::purple},
    {TetrominoType::Z, TDT4102::Color::red}
};

TetrisWindow::TetrisWindow() 
    : AnimationWindow{50, 50, 30*15, 30*22, "Tetris"} {

    gridMatrix.resize(height);
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            gridMatrix.at(i).push_back(TetrominoType::NONE);
        }
    }
    generateRandomTetromino();
}

void TetrisWindow::generateRandomTetromino(){
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution distribution(0,8);

    TetrominoType whatBlock = static_cast<TetrominoType>(distribution(engine));

    Tetromino Block(startpunkt, whatBlock);
    currentTetromino = Block;
}

void TetrisWindow::drawCurrentTetromino(){
    for (int i=0;i<currentTetromino.getMatrixSize();i++){
        for (int j=0;j<currentTetromino.getMatrixSize();j++){
            if (currentTetromino.blockExist(i,j)){
                
                TDT4102::Point Cordinates = {currentTetromino.getPosition().x+j*blockSizes,
                currentTetromino.getPosition().y+i*blockSizes};

                TDT4102::Color Color = toColor.at(currentTetromino.getBlock(i,j));
                
                draw_rectangle(Cordinates, blockSizes, blockSizes, Color);
            }
        }
    }
}

void TetrisWindow::moveTetrominoDown(){
    if (currentTetromino.getPosition().y != blockSizes*height-blockSizes*2){
        currentTetromino.moveDown();
    } 
}


void TetrisWindow::fastenTetromino(){
    for (int i=0;i<currentTetromino.getMatrixSize();i++){
        for (int j=0;j<currentTetromino.getMatrixSize();j++){
            if (currentTetromino.blockExist(i,j)){
                TDT4102::Point Coordinates = {currentTetromino.getPosition().x+j*blockSizes,
                currentTetromino.getPosition().y+i*blockSizes};

                int column = Coordinates.x/blockSizes;
                int row= Coordinates.y/blockSizes;
                if (column<gridMatrix.at(0).size() && row<gridMatrix.size()){
                    gridMatrix.at(row).at(column) = currentTetromino.getBlock(i,j);
                }
            }
        }
    }
}

void TetrisWindow::drawGridMatrix(){
    for (int i=0;i<gridMatrix.size();i++){
        for (int j=0;j<gridMatrix.at(0).size();j++){
            if (gridMatrix.at(i).at(j) != TetrominoType::NONE){
                TDT4102::Point Cordinates = {j*blockSizes,i*blockSizes};
                draw_rectangle(Cordinates, blockSizes, blockSizes,TDT4102::Color::grey);
            }
        }
    }
}

void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while(!should_close()) { 
        framesSinceLastTetronimoMove++;
        drawGridMatrix();
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/
            //Kall moveTetrominoDown() her
            moveTetrominoDown();
            /********************************************************/
        }
        handleInput();
        
        /********************************************************/
        //Kall draw-funksjonene her
        drawCurrentTetromino();
        /********************************************************/

        next_frame();
    }
}


void TetrisWindow::handleInput() {

    static bool lastDownKeyState = false;
    static bool lastUpKeyState = false;
    static bool lastRightKeyState = false;
    static bool lastLeftKeyState = false;

    static bool lastTest = false;

    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);
    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);

    bool currentTest = is_key_down(KeyboardKey::Z);
    
    if(currentDownKeyState && !lastDownKeyState && currentTetromino.getPosition().y != blockSizes*height-blockSizes*2) { // remmeber restrictions
        currentTetromino.moveDown();
    }

    if(currentUpKeyState && !lastUpKeyState) {
        currentTetromino.rotateClockwise();
    }

    if(currentRightKeyState && !lastRightKeyState && currentTetromino.getPosition().x != blockSizes*width-blockSizes*2) {
        currentTetromino.moveRight();
    }

    if(currentLeftKeyState && !lastLeftKeyState && currentTetromino.getPosition().x != 0) {
        currentTetromino.moveLeft();
    }

    if(currentTest && !lastTest){
        fastenTetromino();
    }

    lastDownKeyState = currentDownKeyState;
    lastUpKeyState = currentUpKeyState;
    lastRightKeyState = currentRightKeyState;
    lastLeftKeyState = currentLeftKeyState;
    lastTest = currentTest;
}