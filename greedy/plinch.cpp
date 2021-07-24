#include<iostream>
#include<vector>
using namespace std;
int main(){
	int t,s,k,op,res;
	vector<int> ops;
	vector<int> ress;
	cin>>k;
	t = k;
	s = k;
	while(t--){
		cin>>op;
		ops.push_back(op);
	}
	while(s--){
		cin>>res;
		ress.push_back(res);
	}
	cout<<"\n";
	if(ops.size() != ress.size()){
		cout<<"WRONG TCs\n";
	}else{
		for(int i=0; i<ress.size(); ++i){
			if(ops[i]!=ress[i]){
				cout<<ops[i]<<" : "<<ress[i]<<" : "<<"Wrong\n";
			} 
		}	
	}
	return 0;
}
