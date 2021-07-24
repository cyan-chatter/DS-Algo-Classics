 #include<iostream>
 using namespace std;
 
 int maxSubArraySumDnC(int *arr, int s, int e){
 	if(s>=e){
 		return arr[s];
	 }
	int mid = (s+e)/2;
	int left = maxSubArraySumDnC(arr,s,mid);
	int right = maxSubArraySumDnC(arr,mid+1,e);
	return max(left+right, max(left,right)); 
 }
 
 
 int main(){
 	int arr[] = {-4,8,-6,10,-5,7};
 	int n = sizeof(arr)/sizeof(int);
 	cout<<maxSubArraySumDnC(arr,0,n-1);
 	return 0;
 }
