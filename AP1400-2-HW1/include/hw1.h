#ifndef AP_HW1_H
#define AP_HW1_H
#include<vector>
using std::size_t;
namespace algebra{
    using Matrix = std::vector<std::vector<double>>;
    Matrix zeros(size_t n,size_t m);//#1

    Matrix ones(size_t n, size_t m);//#2

    Matrix random(size_t n, size_t m, double min, double max);//#3

    void show(const Matrix& matrix);//#4

    Matrix multiply(const Matrix& matrix, double c);//#5

    Matrix multiply(const Matrix& matrix1, const Matrix& matrix2);//#6

    Matrix sum(const Matrix& matrix, double c);//#7

    Matrix sum(const Matrix& matrix1, const Matrix& matrix2);//#8

    Matrix transpose(const Matrix& matrix);//#9

    Matrix minor(const Matrix& matrix, size_t n, size_t m);//#10

    double determinant(const Matrix& matrix);//#11

    Matrix inverse(const Matrix& matrix);//#12

    Matrix concatenate(const Matrix& matrix1, const Matrix& matrix2, int axis = 0);//#13

    Matrix ero_swap(const Matrix& matrix, size_t r1, size_t r2);//#14

    Matrix ero_multiply(const Matrix& matrix, size_t r, double c);//#15

    Matrix ero_sum(const Matrix& matrix, size_t r1, double c, size_t r2);//#16

    Matrix upper_triangular(const Matrix& matrix);//#17
}

#endif //AP_HW1_H
