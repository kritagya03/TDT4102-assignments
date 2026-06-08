#pragma once
#include <iostream>


class Matrix{
private:
    double Rows;
    double Columns;
    double** matrix=nullptr;

public:
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix();
    Matrix(const Matrix& rhs);
    Matrix& operator=(Matrix m);

    double get(int row, int col) const;
    void set(int row, int col, double value);
    double getRows() const;
    double getColumns() const;
    friend std::ostream& operator<<(std::ostream& os, Matrix& m);
    friend Matrix operator+(Matrix& ma1, Matrix& ma2);
    friend void operator+=(Matrix& ma1, Matrix& ma2);
};