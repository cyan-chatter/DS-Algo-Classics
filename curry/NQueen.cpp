#include<iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n){
	//column
	for(int row=0; row<i; row++){
		if(board[row][j] == 1){
			return false;
		}
	}
	 
	//left diagonal
	int x = i;
	int y = j;
	
	while(x>=0 && y>=0){
		if(board[x][y] == 1){
			return false;
		}
		x--;
		y--;
	}
	
	//right diagonal
	x = i;
	y = j;
	
	while(x>=0 && y<n){
		if(board[x][y] == 1){
			return false;
		}
		x--;
		y++;
	}
	
	return true;
}

bool NQueen(int board[][10], int i, int n){
	if(i == n){
		//print board
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(board[i][j] == 1){
					cout<<" Q ";
				}
				else{
					cout<<" _ ";
				}
			}
			cout<<"\n";
		}
		cout<<"\n \n";
		return false;
	}
	for(int j=0; j<n; j++){
		if(isSafe(board, i, j, n)){
			//place the queen assuming i,j i right position
			board[i][j] = 1;
			bool nextQueenIsValid = NQueen(board, i+1, n);
			if(nextQueenIsValid){
				return true;
			}
			//i,j, is not right position
			board[i][j] = 0; //backtrack
		}
	}
	//tried every position in the current row and found none
	return false;	
}

int main(){
	int n;
	int board[10][10] = {0};
	cin>>n;
	NQueen(board, 0, n);
	return 0;
}
