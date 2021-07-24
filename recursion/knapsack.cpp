#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector< pair <int,int> > items, int n, int w){
    if(n==0 || w==0){
        return 0;
    }
    int inc=0,exc=0;
    if(items[n-1].second <= w){
        inc = items[n-1].first + knapsack(items,n-1,w-items[n-1].second);
    }
    exc = knapsack(items,n-1,w);
    return (inc > exc ? inc : exc);
}

int main(){
    cout<<"Hello Wanker\n";
    int n,p,w,W;
    cin>>n>>W;
    vector< pair <int,int> > items;
    for(int i=0; i<n; ++i){
        cin>>p>>w;
        items.push_back(make_pair(p,w));
    }
    cout<<knapsack(items,n,W);
    return 0;
}