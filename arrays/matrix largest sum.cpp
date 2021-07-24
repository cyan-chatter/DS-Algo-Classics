#include<iostream>
using namespace std;

int main()
{
	int mat[10][10],m,n,row=0,col=0,sum=0,maxRsum=0,maxCsum=0;
	
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		sum=0;
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
			sum+=mat[i][j];
		}
		if(sum>maxRsum)
		{
			maxRsum=sum;
			row=i;
		}
		
	}	

	for(int i=0;i<n;i++)
	{
		sum=0;
		for(int j=0;j<m;j++)
		{
			sum+=mat[j][i];
		}
		if(sum>maxCsum)
		{
			maxCsum=sum;
			col=i;
		}
	}

if(maxCsum>maxRsum)
	cout<<"\n"<<maxCsum<<" at column index: "<<col<<"\n";
else cout<<"\n"<<maxRsum<<" at row index: "<<row<<"\n";

return 0;
}
