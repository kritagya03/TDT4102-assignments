#include "Matrix.h"
#include <iostream>
#include <utility>

Matrix::Matrix(int nRows, int nColumns){
    Rows=nRows;
    Columns=nColumns;
    matrix=new double*[nRows];

    for (int i=0;i<nRows;i++){
        matrix[i]=new double[nColumns];
        
        for (int j=0;j<nColumns;j++){
            matrix[i][j]=0;
        }
    }
}

Matrix::Matrix(int nRows) : Matrix(nRows, nRows){

    for (int i = 0; i < nRows; i++) {
        matrix[i][i] = 1;
    }
    // Rows=nRows;
    // Columns=nRows;

    // matrix=new double* [nRows];

    // int counter=0;
    // for (int i=0;i<nRows;i++){
    //     matrix[i]=new double[nRows];

    //     for (int j=0;j<nRows;j++){
    //         if (counter==j){
    //             matrix[i][j]=1;
    //         } else{
    //             matrix[i][j]=0;
    //         }
    //     }
    //     counter++;
    // }
}

Matrix::~Matrix(){
    for (int i=0;i<Rows;i++){
        delete[] matrix[i];
    }

    delete[] matrix;

    std::cout<< "matrix deleted!";
}

double Matrix::get(int row, int col) const{
    return matrix[row][col];
}

void Matrix::set(int row, int col, double value){
    matrix[row][col]=value;
}

double Matrix::getRows() const{
    return Rows;
}

double Matrix::getColumns() const{
    return Columns;
}

std::ostream& operator<<(std::ostream& os, Matrix& m){
    for (int i=0;i<m.Rows;i++){
        os << "[";
        for (int j=0;j<m.Columns;j++){
            os << m.matrix[i][j] <<" ";
        }
        os << "] \n";
    }
    return os;
}

Matrix::Matrix(const Matrix& rhs){
    this->Rows=rhs.Rows;
    this->Columns=rhs.Columns;

    this->matrix = new double*[rhs.Rows];
    for (int i=0;i<rhs.Rows;i++){
        this->matrix[i]=new double[rhs.Columns];
        for (int j=0; j<rhs.Columns;j++){
            this->matrix[i][j]=rhs.matrix[i][j];
        }
    }
}

Matrix& Matrix::operator=(Matrix rhs){
    Rows=rhs.Rows;
    this->Columns=rhs.Columns;

    std::swap(this->matrix,rhs.matrix);
    return *this;
}

void operator+=(Matrix& ma1, Matrix& ma2){
    Matrix& result=ma1;
    for (int i=0;i<ma1.Rows;i++){        
        for (int j=0;j<ma1.Columns;j++){
                result.matrix[i][j]=ma1.matrix[i][j]+ma2.matrix[i][j];
        }
    }
}

Matrix operator+(Matrix& ma1, Matrix& ma2){
    Matrix result(ma1.Rows,ma2.Columns);
    for (int i=0;i<ma1.Rows;i++){        
        for (int j=0;j<ma1.Columns;j++){
                result.matrix[i][j]=ma1.matrix[i][j]+ma2.matrix[i][j];
        }
    }
    return result;
}