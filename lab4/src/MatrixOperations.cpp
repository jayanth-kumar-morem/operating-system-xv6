#include<iostream>
#include<bits/stdc++.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "log.h"
#include "MatrixScalerOperations.h"
#include "MatrixOperations.h"
using namespace std;
    vector<vector<int>> MatrixOperations::addMatrices(vector<vector<int>> a, vector<vector<int>> b){
        if(!a.size()){
            
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Empty Matrix";
            endLogger();
            exit(3);
            return a;
        }
        if(a.size()!=b.size() || a[0].size()!=b[0].size()){
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Invalid Size... Exiting...";
            endLogger();
            exit(3);
            return a;
        }
        int n=a.size(),m=a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]+=b[i][j];
            }
        }
        return a;
    }
    vector<vector<int>> MatrixOperations::subtractMatrices(vector<vector<int>> a, vector<vector<int>> b){
        if(!a.size()){
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Empty Matrix";
            endLogger();
            exit(3);
            return a;
        }
        if(a.size()!=b.size() || a[0].size()!=b[0].size()){
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Invalid Size... Exiting...";
            endLogger();
            exit(3);
            return a;
        }
        int n=a.size(),m=a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]-=b[i][j];
            }
        }
        return a;
    }
    vector<vector<int>> MatrixOperations::multiplyMatrices(vector<vector<int>> mat1,vector<vector<int>> mat2) {
        int R1=mat1.size(),C2=mat2[0].size(),R2=mat2.size(),C1=mat1[0].size();
        vector<vector<int>> res;
        if(C1!=R2){
            
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Invalid Size... Exiting...";
            endLogger();
            exit(3);

            return res;
        }
        for(int i=0;i<R1;i++){
            vector<int> temp;
            for(int j=0;j<C2;j++){
                temp.push_back(0);
            }
            res.push_back(temp);
        }

        for (int i = 0; i < R1; i++) {
            for (int j = 0; j < C2; j++) {
                res[i][j] = 0;
                for (int k = 0; k < R2; k++) {
                    res[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        return res;
    }
    vector<vector<int>> MatrixOperations::transposeMatrix(vector<vector<int>> mat1)
    {
        int n=mat1.size();
        vector<vector<int>> res;
        if(!n){
            
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Empty Matrix";
            endLogger();
            exit(3);
            return res;
        }
        int m=mat1[0].size();
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(0);
            }
            res.push_back(temp);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[j][i]=mat1[i][j];
            }
        }
        return res;
    }
    void MatrixOperations::getCofactor(vector<vector<int>> mat, vector<vector<int>> &temp, int p,int q, int n)
    {
        int i = 0, j = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row != p && col != q)
                {
                    temp[i][j++] = mat[row][col];
                    if (j == n - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }
    int MatrixOperations::determinantOfMatrix(vector<vector<int>> mat, int n)
    {
        int D = 0;
        if (n == 1)
            return mat[0][0];
        if(!n)  return 0;
        if(n!=mat[0].size()){
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Invalid Size... Exiting...";
            endLogger();
            exit(3);
            return -1;
        }
        vector<int> t(n,0);
        vector<vector<int>> temp(n,t);

        int sign = 1;  
        for (int f = 0; f < n; f++)
        {
            getCofactor(mat, temp, 0, f, n);
            D += sign * mat[0][f]* determinantOfMatrix(temp, n - 1);
            sign = -sign;
        }
        return D;
    }