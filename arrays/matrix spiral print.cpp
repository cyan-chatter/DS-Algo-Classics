#include<iostream>
using namespace std;

void spiralPrint(int mat[10][10],int row,int col)
{
	int startRow,endRow,startCol,endCol;
	startRow=0;
	startCol=0;
	endRow=row-1;
	endCol=col-1;
	
	while(startRow<=endRow && startCol<=endCol)
	{
		for(int i=startCol;i<=endCol;i++)
			cout<<mat[startRow][i]<<" ";
			++startRow;
			cout<<"\n";
		for(int i=startRow;i<=endRow;i++)
			cout<<mat[i][endCol]<<" ";
			--endCol;
		cout<<"\n";
		if(startRow<endRow)
		{
			for(int i=endCol;i>=startCol;i--)
			cout<<mat[endRow][i]<<" ";
			--endRow;
			cout<<"\n";
		}
		
		if(startCol<endCol)
		{
			
			for(int i=endRow;i>=startRow;i--)
			cout<<mat[i][startCol]<<" ";
			++startCol;
			cout<<"\n";
		}
		
		
	}
	
	
}

int main()
{
	int mat[10][10]={ },row,col;
	
	cin>>row>>col;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>mat[i][j];
		}
	}	
	cout<<"\n";
	spiralPrint(mat,row,col);
	
	
	return 0;
}
