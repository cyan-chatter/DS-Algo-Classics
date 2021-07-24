#include<iostream>
using namespace std;
int c;
void ratInMaze(char maze[101][101], int i, int j, int m, int n){
    if(i==m && j==n){
        maze[i][j] = '0';
        for(int k=0; k<=m; ++k){
            for(int l=0; l<=n; ++l){
                cout<<maze[k][l];
            }
            cout<<"\n";
        }
        cout<<"\n";
        ++c;
        cout<<"c: "<<c<<"\n";
        maze[i][j] = '.';
        return;
    }
    if(i>m || j>n){
        return;
    }
    if(maze[i][j] == '*'){
        return;
    }
    maze[i][j] = '0';
    ratInMaze(maze,i,j+1,m,n);
    ratInMaze(maze,i+1,j,m,n);
    maze[i][j] = '.';

}


int main(){
    int m=4,n=18;
    char maze[101][101] = {
            ".......*......*.*.*",
            "****.......*...*.*.",
            "*.***.*........*...",
            "*.*.......**......."
    };
    ratInMaze(maze,0,0,m-1,n-1);
    cout<<"Number of paths: "<<c;
    return 0;
}