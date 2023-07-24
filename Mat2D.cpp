#include "Mat2D.h"
#include <iostream>

Mat2D::Mat2D(const int rows, const int cols) : rows(rows), cols(cols) {
  int size = rows * cols;
  data = new int[size]{};
}

Mat2D::~Mat2D() {
  if (data != nullptr) {
    delete[] data;
  }
}

int Mat2D::Rows() { return rows; }

int Mat2D::Cols() { return cols; }

void Mat2D::Print() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << data[i * cols + j] << " ";
    }

    std::cout << std::endl;
  }
}

int *Mat2D::operator[](int idx) {
  return data + idx * cols;
  return nullptr;
}
