#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H
#include<iostream>
#include<bits/stdc++.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "log.h"
#include "MatrixOperations.h"
#include "Matrix.h"
using namespace std;
class MatrixOperations{
    public:
    vector<vector<int>> addMatrices(vector<vector<int>> a, vector<vector<int>> b);
    vector<vector<int>> subtractMatrices(vector<vector<int>> a, vector<vector<int>> b);
    vector<vector<int>> multiplyMatrices(vector<vector<int>> mat1,vector<vector<int>> mat2);
    vector<vector<int>> transposeMatrix(vector<vector<int>> mat1);
    void getCofactor(vector<vector<int>> mat, vector<vector<int>> &temp, int p,int q, int n);
    int determinantOfMatrix(vector<vector<int>> mat, int n);
};
#endif