#include "hw1.h"
// #include "../include/hw1.h"
#include <iomanip>
#include <vector>
#include <iostream>
#include <random>
using std::cout;
using std::endl;
using std::logic_error;
using std::setprecision;
using std::vector;
// using std::double;

namespace algebra{
    using Matrix = std::vector<std::vector<double>>;
    Matrix zeros(size_t n,size_t m){//#1
        if(n<=0 || m<=0){
            throw logic_error("wrong col or row\n");
        }
        Matrix matrix;
        for(int i=0;i<n;i++){
            vector<double> zroline(m, 0);
            matrix.push_back(zroline);
        }
        return matrix;
    }

    Matrix ones(size_t n, size_t m){//#2
        if(n<=0 || m<=0){
            throw logic_error("wrong col or row\n");
        }
        Matrix matrix;
        for(int i=0;i<n;i++){
            vector<double> oneline(m, 1);
            matrix.push_back(oneline);
        }
        return matrix;
    }

    double getRandomNumber(double min, double max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(min, max);

        return dist(gen);
    }
    int getIntRandomNumber(int min, int max) {
        std::random_device rd; // 获取真随机数种子
        std::mt19937 gen(rd()); // 使用种子初始化随机数生成器
        std::uniform_int_distribution<int> dist(min, max); // 创建分布对象，指定范围

        return dist(gen); // 生成随机数
    }
    Matrix random(size_t n, size_t m, double min, double max){//#3
        if(n<=0 || m<=0){
            throw logic_error("wrong col or row\n");
        }
        if(min>=max){
            throw logic_error("wrong random range\n");
        }
        Matrix matrix = zeros(n,m);
        for(int i=0;i<n;i++){
            vector<double> line(m);
            for(int j=0;j<m;j++){
                matrix[i][j] = getRandomNumber(min,max);
            }
        }
        return matrix;
    }
    Matrix randomInt(size_t n, size_t m, double min, double max){//#3
        if(n<=0 || m<=0){
            throw logic_error("wrong col or row\n");
        }
        if(min>=max){
            throw logic_error("wrong random range\n");
        }
        Matrix matrix = zeros(n,m);
        for(int i=0;i<n;i++){
            vector<double> line(m);
            for(int j=0;j<m;j++){
                matrix[i][j] = getIntRandomNumber(min,max);
            }
        }
        return matrix;
    }

    void show(const Matrix& matrix){//#4
        cout << "[ ";
        for(int i=0;i<matrix.size();i++){
            if(i>0) cout << "  ";
            for(int j=0;j<matrix[i].size();j++){
                if(j>0) cout<<", ";
                cout << std::fixed << std::setprecision(3) << matrix[i][j];
            }
            if(i==(matrix.size()-1)) cout << " ]";
            cout << endl;
        }
    }

    Matrix multiply(const Matrix& matrix, double c){//#5
        Matrix newMatrix = zeros(matrix.size(),matrix[0].size());
        for(int i=0;i<matrix.size();i++){
            for(int j = 0;j<matrix[i].size();j++){
                newMatrix[i][j] = matrix[i][j]*c;
            }
        }
        return newMatrix;
    }

    Matrix multiply(const Matrix& matrix1, const Matrix& matrix2){//#6
        //matrix(n*m); matrix2(m*p); resultMatrix(n*p)
        if(matrix1.empty()||matrix2.empty()){
            Matrix newMatrix{};
            return newMatrix;
        }
        if(matrix1[0].size()!=matrix2.size()){
            throw logic_error("wrong matrix size\n");
        }
        Matrix newMatrix = zeros(matrix1.size(),matrix2[0].size());
        for(int i=0;i<matrix1.size();i++){
            for(int j = 0;j<matrix2[0].size();j++){
                for(int k = 0;k<matrix1[0].size();k++){
                    newMatrix[i][j] += matrix1[i][k]*matrix2[k][j];
                }
            }
        }
        return newMatrix;
    }

    Matrix sum(const Matrix& matrix, double c){//#7
        if(matrix.empty()){
            Matrix newMatrix{};
            return newMatrix;
        }
        Matrix newMatrix = zeros(matrix.size(),matrix[0].size());
        for(int i=0;i<matrix.size();i++){
            for(int j = 0;j<matrix[i].size();j++){
                newMatrix[i][j] = matrix[i][j]+c;
            }
        }
        return newMatrix;
    }

    Matrix sum(const Matrix& matrix1, const Matrix& matrix2){//#8
        if(matrix1.empty()&&matrix2.empty()){
            Matrix newMatrix{};
            return newMatrix;
        }
        else if(matrix1.size()!=matrix2.size()||matrix1[0].size()!=matrix2[0].size()){
            throw logic_error("wrong matrix size\n");
        }
        
        Matrix newMatrix = zeros(matrix1.size(),matrix1[0].size());
        for(int i=0;i<matrix1.size();i++){
            for(int j = 0;j<matrix1[i].size();j++){
                newMatrix[i][j] = matrix1[i][j]+matrix2[i][j];
            }
        }
        return newMatrix;
    }

    Matrix transpose(const Matrix& matrix){//#9
        if(matrix.empty()){
            Matrix newMatrix{};
            return newMatrix;
        }
        Matrix newMatrix = zeros(matrix[0].size(),matrix.size());
        for(int i=0;i<matrix[0].size();i++){
            for(int j = 0;j<matrix.size();j++){
                newMatrix[i][j] = matrix[j][i];
            }
        }
        return newMatrix;
    }

    Matrix minor(const Matrix& matrix, size_t n, size_t m){//#10 子式，删除特定的行和列
        Matrix newMatrix;
        for (int i = 0; i < matrix.size(); i++) {
            if (i == n) {
                continue;
            }
            std::vector<double> newLine;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (j == m) {
                    continue;
                }
                newLine.push_back(matrix[i][j]);
            }
            newMatrix.push_back(newLine);
        }
        return newMatrix;
    }

    double determinant(const Matrix& matrix){//#11
        if(matrix.empty()) return 1;
        else if(matrix.size()!=matrix[0].size()){
            throw logic_error("wrong matrix size");
        }
        else if(matrix.size()==1){
            return matrix[0][0];
        }
        else if(matrix.size()==2){
            return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
        }
        else{
            double result = 0;
            for(int i=0;i<matrix.size();i++){
                result += matrix[i][0]*pow(-1,i)*determinant(minor(matrix,i,0));
            }
            return result;
        }
    }

    Matrix adjoint(const Matrix& matrix){
        Matrix newMatrix = zeros(matrix.size(),matrix[0].size());
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                newMatrix[i][j] = determinant(minor(matrix,i,j))*pow(-1,i+j);
            }
        }
        return transpose(newMatrix);
    }

    Matrix inverse(const Matrix& matrix){//#12
        if(matrix.empty()){
            Matrix newMatrix{};
            return newMatrix;
        }
        else if(matrix.size()!=matrix[0].size()){
            throw logic_error("wrong matrix size\n");
        }
        else if(determinant(matrix)==0){
            throw logic_error("non singular matrix");
        }
        Matrix newMatrix = adjoint(matrix);
        return multiply(newMatrix,(1/determinant(matrix)));
    }

    Matrix concatenate(const Matrix& matrix1, const Matrix& matrix2, int axis){//#13
    // 0: 纵向拼接
    // 1: 横向拼接
        if(axis == 0){
            if(matrix1[0].size()!=matrix2[0].size()){
                throw logic_error("wrong matrix size\n");
            }
            Matrix newMatrix;
            // show(matrix1);
            // show(matrix2);
            for(int i=0;i<matrix1.size();i++){
                newMatrix.push_back(matrix1[i]);
            }
            for(int i=0;i<matrix2.size();i++){
                newMatrix.push_back(matrix2[i]);
            }
            // show(matrix2);
            return newMatrix;
        }
        else if(axis == 1){
            if(matrix1.size()!=matrix2.size()){
                throw logic_error("wrong matrix size\n");
            }
            Matrix newMatrix = zeros(matrix1.size(),(matrix1[0].size()+matrix2[0].size()));
            for(int i=0;i<matrix1.size();i++){
                for(int j = 0;j<matrix1[0].size();j++){
                    newMatrix[i][j] = matrix1[i][j];
                }
            }
            for(int i=0;i<matrix1.size();i++){
                for(int j = 0;j<matrix2[0].size();j++){
                    newMatrix[i][matrix1[0].size()+j] = matrix2[i][j];
                }
            }
            return newMatrix;
        }
        else{
            throw logic_error("wrong axis value(0 or 1)\n");
        }
    }

    Matrix ero_swap(const Matrix& matrix, size_t r1, size_t r2){//#14
        if(matrix.size()<=r1||matrix.size()<=r2){
            throw logic_error("wrong matrix size or row indexs\n");
        }
        Matrix newMatrix;
        for(int i=0;i<matrix.size();i++){
            if(i==r1){
                newMatrix.push_back(matrix[r2]);
            }
            else if(i==r2){
                newMatrix.push_back(matrix[r1]);
            }
            else{
                newMatrix.push_back(matrix[i]);
            }
        }
        return newMatrix;
    }

    Matrix ero_multiply(const Matrix& matrix, size_t r, double c){//#15
        if(r>matrix.size()){
            throw logic_error("wrong row index\n");
        }
        Matrix newMatrix;
        for(int i=0;i<matrix.size();i++){
            if(i == r){
                vector<double> newLine = matrix[i];
                for(int j=0;j<newLine.size();j++){
                    newLine[j]*=c;
                }
                newMatrix.push_back(newLine);
            }
            else{
                newMatrix.push_back(matrix[i]);
            }
        }
        return newMatrix;
    }

    Matrix ero_sum(const Matrix& matrix, size_t r1, double c, size_t r2){//#16
        //r1*c+r2-->r2
        Matrix newMatrix;
        for(int i=0;i<matrix.size();i++){
            if(i==r2){
                vector<double> newLine = matrix[r1];
                for(int j=0;j<newLine.size();j++){
                    newLine[j] *= c;
                    newLine[j] += matrix[r2][j];
                }
                // newLine = ero_sum(newLine, ero_multiply(matrix[r1],c));
                newMatrix.push_back(newLine);
            }
            else{
                newMatrix.push_back(matrix[i]);
            }
        }
        return newMatrix;
    }

    void mul_sum(Matrix& matrix, size_t r1, double c, size_t r2) {
        for (int i = 0; i < matrix[r2].size(); i++) {
            matrix[r2][i] += (matrix[r1][i] * c);
        }
    }
    Matrix upper_triangular(const Matrix& matrix){//#17
        // Matrix newMatrix = ero_multiply(matrix,0,1);
        // cout << "=========================" <<endl;
        // show(newMatrix);
        // for(int i = 0;i<matrix.size();i++){
        //     for(int j = i+1;j<matrix.size();j++){
        //         int k=0;
        //         while(matrix[i][k]==0) k++;
        //         newMatrix = ero_sum(newMatrix,i,(-1*newMatrix[j][k]/newMatrix[i][k]),j);
        //         show(newMatrix);
        //         cout<< "          |"<<endl;
        //     }
        // }
        // return newMatrix;
        if (matrix.empty()) {
            return Matrix{};
        }
        if (matrix.size() != matrix[0].size()) {
            throw logic_error("not a square matrix\n");
        }
        Matrix newMatrix = ero_multiply(matrix, 0, 1);
        if (newMatrix[0][0] == 0) {
            int row = 1;
            while (newMatrix[row][0] == 0 && row < newMatrix.size()) {
                row++;
            }
            if (row == newMatrix.size()) {
                throw logic_error("impossible");
            }
            newMatrix = ero_swap(newMatrix, 0, row);
        }

        auto m{matrix.size()};

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                mul_sum(newMatrix, i, (-newMatrix[j][i] / newMatrix[i][i]), j);
            }
        }
        return newMatrix;
    }

}//namespace algebra end


// using namespace algebra;
// int main(){
//     // Matrix matrix = random(4,5,0.0,10.0);
//     // show(matrix);
//     // matrix = multiply(matrix,2.0);
//     // show(matrix);
//     // Matrix matrix2 = random(5,4,0.0,10.0);
//     // matrix = multiply(matrix,matrix2);
//     // show(matrix);
//     // matrix = sum(matrix,-100);
//     // show(matrix);
//     // Matrix matrix3 = random(4,4,0.0,10.0);
//     // matrix = sum(matrix,matrix3);
//     // show(matrix);
//     // matrix = transpose(matrix);
//     // show(matrix);
//     // matrix = minor(matrix,1,1);
//     // show(matrix);
//     // matrix = random(4,4,0,3);
//     // show(matrix);
//     // cout << determinant(matrix)<<endl;
//     // Matrix matrix_1 = inverse(matrix);
//     // show(multiply(matrix, matrix_1));
//     // show(concatenate(matrix, matrix_1,0));
//     // show(concatenate(matrix, matrix_1,1));
//     // show(ero_swap(matrix,1,2));
//     // show(ero_multiply(matrix,1,2));
//     // show(ero_sum(matrix,1,2,2));
//     // Matrix matrix = random(5,5,0,10);
//     // show(upper_triangular(matrix));
//     // Matrix m1{};
//     // Matrix m2{};
//     // show(multiply(m1, m2));
//     // Matrix non_singular_matrix{{1, 1.5, -1.75, 2}, {2, 2.5, -2.75, 3}, {3, 3.5, -3.75, 4}, {4, 4.5, 4.75, 5}};
//     // show(inverse(non_singular_matrix));
//     Matrix matrix1 = random(2, 3, 0, 1);
//     Matrix matrix2 = random(2, 1, 0, 1);
//     show(matrix1);
//     show(matrix2);
//     // Matrix matrix = concatenate(matrix1,matrix2,0);
//     show(concatenate(matrix1,matrix2,1));
//     // Matrix matrix{{1,2}};
//     // show(matrix);
//     // show(ero_swap(matrix,0,1));
    
// }