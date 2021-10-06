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
    vector<vector<int>> AddScaler(vector<vector<int>> mat,int x);
    vector<vector<int>> subtractScaler(vector<vector<int>> mat,int x);
    vector<vector<int>> multiplyScaler(vector<vector<int>> mat,int x);
    vector<vector<int>> divisionScaler(vector<vector<int>> mat,int x);
};
#endif