#include<iostream>
using namespace std;

int count=10;

bool defectiveCheck(int xdef,int ydef,int xs,int xe,int ys,int ye)
{
	if((xdef<=xe && xdef>=xs)&&(ydef<=ye && ydef>=ys))
		return true;
	
	return false;
}

pair<int,int> defPosition(int xs,int xe,int ys,int ye,int xdef,int ydef,int t)
{
	int xmid=(xs+xe)/2;
	int ymid=(ys+ye)/2;
	
	pair<int,int> p;
	
	if(defectiveCheck(xdef,ydef,xs,xmid,ys,ymid)&& t==1)
		return make_pair(xdef,ydef);
	if(defectiveCheck(xdef,ydef,xmid+1,xe,ys,ymid) && t==2)
		return make_pair(xdef,ydef);
	if(defectiveCheck(xdef,ydef,xmid+1,xe,ymid+1,ye) && t==3)
		return make_pair(xdef,ydef);
	if(defectiveCheck(xdef,ydef,xs,xmid,ymid+1,ye) && t==4)
		return make_pair(xdef,ydef);
		
	if(t==1)
		p=make_pair(xmid,ymid);
	if(t==2)
		p=make_pair(xmid+1,ymid);
	if(t==3)
		p=make_pair(xmid+1,ymid+1);
	if(t==4)
		p=make_pair(xmid,ymid+1);		
	
	return p;		
}

void defective(int arr[][8],int xdef,int ydef,int xs=0,int xe=7,int ys=0,int ye=7)
{
	//Base Case
	int s=xe-xs+1;
	
	if(s==2)
	{
		for(int i=xs ; i<=xe ; i++)
		{
			for(int j=ys ; j<=ye ; j++)
			{
				if(!(i==xdef && j==ydef))
					arr[i][j]=count;
			}
		}
		count++;
		return;
	}
	
	// Divide it into four partition	
	int xmid=(xs+xe)/2;
	int ymid=(ys+ye)/2;
	
	pair<int,int> def1=defPosition(xs,xe,ys,ye,xdef,ydef,1);
	pair<int,int> def2=defPosition(xs,xe,ys,ye,xdef,ydef,2);
	pair<int,int> def3=defPosition(xs,xe,ys,ye,xdef,ydef,3);
	pair<int,int> def4=defPosition(xs,xe,ys,ye,xdef,ydef,4);
	
	defective(arr,def1.first,def1.second,xs,xmid,ys,ymid);	
	defective(arr,def2.first,def2.second,xmid+1,xe,ys,ymid);
	defective(arr,def3.first,def3.second,xmid+1,xe,ymid+1,ye);
	defective(arr,def4.first,def4.second,xs,xmid,ymid+1,ye);
	
	if(!defectiveCheck(xdef,ydef,xs,xmid,ys,ymid))
		arr[def1.first][def1.second]=count;
	if(!defectiveCheck(xdef,ydef,xmid+1,xe,ys,ymid))
		arr[def2.first][def2.second]=count;
	if(!defectiveCheck(xdef,ydef,xmid+1,xe,ymid+1,ye))
		arr[def3.first][def3.second]=count;
	if(!defectiveCheck(xdef,ydef,xs,xmid,ymid+1,ye))
		arr[def4.first][def4.second]=count;
	
	count++;
}

int main()
{
	int arr[8][8]={0};
	int x,y;
	cin>>x>>y;
	cout<<endl;
	defective(arr,x,y);
	
	for(int i=0 ; i<=7 ; i++)
		{
			for(int j=0 ; j<=7 ; j++)
			{
				if(i==x&&j==y)
					cout<<"00 ";
				else	
					cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	
	return 0;
}
