#include<iostream>
#include<bits/stdc++.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "Matrix.h"
#include <unistd.h>
#include "MatrixOperations.h"
#include "MatrixScalerOperations.h"
#include "Matrix.h"
#include <vector>
using namespace std;
    Matrix::Matrix(){
        row=0;
        col=0;
    }
    Matrix::Matrix(int r, int c){
        row=r;
        col=c;
        for(int i=0;i<row;i++){
            vector<int> temp;
            for(int j=0;j<col;j++){
                temp.push_back(0);
            }
            mat.push_back(temp);
        }
    }
    void Matrix::enter(){
        int f=0;
        for (int i=0; i<row; i++)
        {
            string temp;
            getline(cin,temp);
            if(!temp.length()){
                i--;
                continue;
            }
            stringstream ss(temp);
            for(int j=0;j<col;j++){
                string substr;
                getline(ss, substr, ',');
                if(!ss.good())  break;
                mat[i][j]=stoi(substr);
            }
        }
    }
    void Matrix::print(){
        for (int u=0; u<row; u++)
        {
            for (int v=0; v<col; v++){
                cout<<mat[u][v]<<" ";
            }
            cout<<endl;
        }
    }