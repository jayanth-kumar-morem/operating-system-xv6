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
    MatrixScalerOperations::MatrixScalerOperations(){
        row=0;
        col=0;
    }
    MatrixScalerOperations::MatrixScalerOperations(int r, int c){
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
    void MatrixScalerOperations::enter(){
        int f=0;
        for (int i=0; i<row; i++)
        {
            // cout<<"i="<<i<<endl;
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
                // cout<<"i="<<i<<" j="<<j<<" = "<<stoi(substr);
                // cout<<atoi(substr.c_str())<<"="<<endl;
            }
        }
    }
    void MatrixScalerOperations::print(){
        for (int u=0; u<row; u++)
        {
            for (int v=0; v<col; v++){
                cout<<mat[u][v]<<" ";
            }
            cout<<endl;
        }
    }
    void MatrixScalerOperations::AddScaler(int x){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mat[i][j]+=x;                
            }
        }
    }
    void MatrixScalerOperations::subtractScaler(int x){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mat[i][j]-=x;                
            }
        }
    }
    void MatrixScalerOperations::multiplyScaler(int x){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mat[i][j]*=x;                
            }
        }
    }
    void MatrixScalerOperations::divisionScaler(int x){
        if(x==0){
            initLogger( "mylogfile.log", ldebug);
            L_(lwarning) << "Division By zero... Exiting... ";
            endLogger();
            exit(3);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mat[i][j]/=x;                
            }
        }
    }