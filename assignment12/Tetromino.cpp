#include "Tetromino.h"
#include <map>
#include <iostream>
#include "Color.h"
    
const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap {
    {
    TetrominoType::J,
    {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 1}
    }
    },
    {
    TetrominoType::T,
    {
        {1, 1, 1},
        {0, 1, 0},
        {0, 0, 0}
    }
    },
    {
    TetrominoType::L,
    {
        {1, 0, 0},
        {1, 0, 0},
        {1, 1, 0}
    }
    },
    {
    TetrominoType::S,
    {
        {1, 0, 0},
        {1, 1, 0},
        {0, 1, 0}
    }
    },
    {
    TetrominoType::I,
    {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0}
    }
    },
    {
    TetrominoType::Z,
    {
        {0, 0, 1},
        {0, 1, 1},
        {0, 1, 0}
    }
    },
    {
    TetrominoType::O,
    {
        {1, 1},
        {1, 1}
    }
    }
};

Tetromino::Tetromino(){
    topLeftCorner={0,0};
    matrixSize=0;
}

Tetromino::Tetromino(TDT4102::Point startingPoint, TetrominoType tetType) : 
topLeftCorner{startingPoint}
{
    std::vector<std::vector<int>> OurMatrix = initialMatrixMap.at(tetType);
    matrixSize=initialMatrixMap.at(tetType).size();

    blockMatrix.resize(matrixSize);

    for(int i=0;i<matrixSize;i++){
        for (int j=0;j<matrixSize;j++){
            if (OurMatrix.at(i).at(j) == 0){
                blockMatrix.at(i).push_back(TetrominoType::NONE);
            } else {
                blockMatrix.at(i).push_back(tetType);
            }
        }
    }
}

void Tetromino::rotateCounterClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    //Andre rotasjon, med hensyn på den midtre raden
    for(int row = 0; row < matrixSize/2; row++){
        for(int column = 0; column < matrixSize; column++){
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize-row-1][column]);
            
        }
    }
}

void Tetromino::rotateClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }
     
    //Andre rotasjon, med hensyn på den midtre kolonnen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < matrixSize/2; column++){
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize-column-1]);
        }
    }
}

void Tetromino::moveDown(){
    topLeftCorner.y+=blockSize;
}

void Tetromino::moveRight(){
    topLeftCorner.x+=blockSize;
}

void Tetromino::moveLeft(){
    topLeftCorner.x-=blockSize;
}

bool Tetromino::blockExist(int row, int column){
    if (row<=matrixSize && column<=matrixSize){
        if (blockMatrix.at(row).at(column)==TetrominoType::NONE){
            return false;
        } else {
            return true;
        }
    } else{
        std::cout << "You outside boy, returning false" <<std::endl;
        return false;
    }
}

TetrominoType Tetromino::getBlock(int row, int column){
    return blockMatrix.at(row).at(column);
}

int Tetromino::getMatrixSize(){
    return matrixSize;
}

TDT4102::Point Tetromino::getPosition(){
    return topLeftCorner;
}