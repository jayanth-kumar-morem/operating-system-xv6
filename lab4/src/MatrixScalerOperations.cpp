#include<iostream>
#include<bits/stdc++.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "MatrixScalerOperations.h"
#include <unistd.h>
#include "MatrixOperations.h"
#include <vector>
using namespace std;
    vector<vector<int>> MatrixScalerOperations::AddScaler(vector<vector<int>> mat,int x){
        if(!mat.size() || !mat[0].size()){
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Invalid Matrix or Empty Matrix Detected ... Exiting";
            endLogger();
            exit(3);
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j]+=x;                
            }
        }
        return mat;
    }
    vector<vector<int>> MatrixScalerOperations::subtractScaler(vector<vector<int>> mat,int x){
        if(!mat.size() || !mat[0].size()){
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Invalid Matrix or Empty Matrix Detected ... Exiting";
            endLogger();
            exit(3);
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j]-=x;                
            }
        }
        return mat;
    }
    vector<vector<int>> MatrixScalerOperations::multiplyScaler(vector<vector<int>> mat,int x){
        if(!mat.size() || !mat[0].size()){
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Invalid Matrix or Empty Matrix Detected ... Exiting";
            endLogger();
            exit(3);
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j]*=x;                
            }
        }
        return mat;
    }
    vector<vector<int>> MatrixScalerOperations::divisionScaler(vector<vector<int>> mat,int x){
        if(!mat.size() || !mat[0].size()){
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Division By zero... Exiting... ";
            endLogger();
            exit(3);
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j]/=x;                
            }
        }
        return mat;
    }