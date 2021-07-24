#include<iostream>
using namespace std;

void wavePrint(int a[100],int n)
{
	for(int i=0;i<n;i=i+2)
	{
		if(i!=0 && a[i]<a[i-1])
			swap(a[i],a[i-1]);
		if(i!=n-1 && a[i]<a[i+1])
			swap(a[i],a[i+1]);	
	}
	
	cout<<endl;
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	
}

int main()
{
	int a[100]={ },n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	wavePrint(a,n);
	
	return 0;
}
