#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<bits/stdc++.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "MatrixScalerOperations.h"
#include "Matrix.h"
#include "MatrixOperations.h"
#include <unistd.h>
#include <vector>
using namespace std;
class Matrix{
    public:
    int row,col;
    vector<vector<int>> mat;
    Matrix();
    Matrix(int r, int c);
    void enter();
    void print();
};
#endif