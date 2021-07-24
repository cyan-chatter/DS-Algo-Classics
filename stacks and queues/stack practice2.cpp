#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s){
	cout<<endl;
	while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
}

void printSpan(int a[], int n){
	stack<int> s; int span[n];
	for(int i=0; i<n; ++i){
		int cp = a[i];
		if(s.empty()){
			s.push(i);
			cout<<"\nEmpty Push:";
			print(s);
			span[i] = 0;
		}else if(!s.empty()){
			if(cp<a[s.top()]){
				s.push(i);
				cout<<"\nPush:";
				print(s);
				span[i] = 1;
			}else{
				while(a[s.top()] < cp){
					s.pop();
					cout<<"\nPop:";
					print(s);
				}
				int lastTop = s.top();
				s.push(i);
				cout<<"\nPush After Pop:";
				print(s);
				span[i] = s.top() - lastTop;			 
			}
		}
	}
	cout<<endl;
	for(int i=0; i<n; ++i){
		cout<<span[i]<<" ";
	}
	cout<<endl;
}


int main(){
	
	int arr[] = {100,80,60,70,60,75,85};
	int n = sizeof(arr)/sizeof(int);
	
	printSpan(arr,n);
	
	return 0;
}
