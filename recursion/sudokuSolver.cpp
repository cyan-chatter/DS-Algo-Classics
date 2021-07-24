#include <iostream>
#include <cmath>
using namespace std;
const int m=9;

bool canput(int sudoku[m][m], int &n ,int &i, int &j, int &num){
    for(int k=0; k<m; ++k){
        if(sudoku[i][k] == num || sudoku[k][j] == num) return false;
    }
    int sn = sqrt(num);
    int srow = (i/sn) * sn;
    int scol = (j/sn) * sn;
    for(int k=0; k<sn; ++k){
        for(int l=0; l<sn; ++l){
            if(sudoku[srow + k][scol + l] == num) return false;
        }
    }
    return true;
}

bool sudokuSolver(int sudoku[m][m], int i, int j, int &n){
    if(i==n){
        for(int k=0; k<m; ++k){
            for(int l=0; l<m; ++l){
                cout<<sudoku[k][l]<<"   ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return true;
    }
    if(j==n){
        return sudokuSolver(sudoku,i+1,0,n);
    }
    if(sudoku[i][j]!=0){
        return sudokuSolver(sudoku,i,j+1,n);
    }
    for(int num = 1; num <= 9; ++num){
        if(canput(sudoku,n,i,j,num)){
            sudoku[i][j] = num;
            if(sudokuSolver(sudoku,i,j+1,n)){
                return true;
            }
        }
    }
    sudoku[i][j] = 0; //backtracking
    return false;
}

int main(){
    int sudoku[m][m] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
    };
    int n = m;
    sudokuSolver(sudoku,0,0,n);
    return 0;
}