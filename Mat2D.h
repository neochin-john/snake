#pragma once

class Mat2D
{
public:
    Mat2D(const int rows, const int cols);
    ~Mat2D();

    int Rows();
    int Cols();

    void Print();
    int* operator[](int idx);
    
private:
    const int rows;
    const int cols;
    int *data;
};
