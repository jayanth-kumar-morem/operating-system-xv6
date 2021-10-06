#ifndef MATRIXSCALEROPERATIONS_H
#define MATRIXSCALEROPERATIONS_H
#include<iostream>
#include<bits/stdc++.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "MatrixScalerOperations.h"
#include <unistd.h>
#include <vector>
using namespace std;
class MatrixScalerOperations{
    public:
    int row,col;
    vector<vector<int>> mat;
    MatrixScalerOperations();
    MatrixScalerOperations(int r, int c);
    void enter();
    void print();
    void AddScaler(int x);
    void subtractScaler(int x);
    void multiplyScaler(int x);
    void divisionScaler(int x);

};
#endif