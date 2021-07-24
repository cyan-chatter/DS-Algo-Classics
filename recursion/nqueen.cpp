#include <bits/stdc++.h>
using namespace std;

bool canPlace(int board[100][100], int i, int j, int n){

    for(int y=0; y<i; ++y){
        if(board[y][j] == 1){
            return false;
        }
    }
    int x = j, y = i;
    while(y>=0 and x>=0){
        if(board[y][x] == 1){
            return false;
        }
        --x; --y;
    }
    x = j, y = i;
    while(y>=0 and x<n){
        if(board[y][x] == 1){
            return false;
        }
        --y;++x;
    }

    return true;
}

 int nqueen(int board[100][100], int i, int &n){
    if(i==n){
        for(int y=0; y<n; ++y){
            for(int x=0; x<n; ++x){
                cout<<board[y][x]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return 1;
    }
    int count = 0;
    for(int j=0; j<n; ++j){
        if(canPlace(board,i,j,n)){
            board[i][j] = 1;
            count += nqueen(board,i+1,n);
            board[i][j] = 0;
        }
    }
    return count;
}

bitset<30> col, d1, d2;

void countNqueen(int r, int &n, int &count){
    if(r==n){
        ++count;
        return;
    }
    for(int c=0; c<n; ++c){
        if(!col[c] && !d1[r-c+n-1] && !d2[r+c]){
            col[c] = d1[r-c+n-1] = d2[r+c] = 1;
            countNqueen(r+1,n,count);
            col[c] = d1[r-c+n-1] = d2[r+c] = 0;
        }
    }

}

int main(){

    int n, board[100][100], count = 0;
    cin>>n;
    cout<<nqueen(board,0,n);
    countNqueen(0,n,count);
    cout<<"\nWays: "<<count;
    return 0;
}
