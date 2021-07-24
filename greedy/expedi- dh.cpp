//dark horcrux
//expedi- spoj
#include<cstdio>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
 
 
using namespace std;
 
#define MX 10004
#define ll long long int
#define f(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define fe(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define fm(x,y,z) for((x)=(y) ; (x)>(z) ; (x)--)
#define FLUSH fflush(stdout)
#define copy(dest,src,size) memcpy(dest,src,size)
struct Station{
 int dis;
 int fuel;
 bool operator <(const Station& p) const{
   return dis > p.dis;
 }
};
Station a[MX];
int heap[MX];
int cur_in;
void insert(int x){
  cur_in++;
  int i=cur_in;
  while(i!=1){
    if(heap[i/2]<x)heap[i]=heap[i/2];
    else break;
    i/=2;
  }
  heap[i]=x;
}
int dmax(){
  if(cur_in==0) return -1;
  int max=heap[1];
  int value = heap[cur_in--];
  int i=1,child;
  while(i*2<=cur_in){
    child = (i*2);
    if((child+1) <= cur_in && heap[child+1] > heap[child]) child++;
    if(heap[child]>value) heap[i]=heap[child];
    else break;
    i=(child);
  }
  heap[i]=value;
  return max;
}
int comp(const void *_x,const void *_y){
    Station *x=(Station *)_x,*y=(Station *)_y;
        return y->dis-x->dis;
}
int main(){
  int n,i,j,k,t,fuel,dis,flag,flag2,l,m;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    for(i=n-1;i>=0;i--){
      scanf("%d %d",&a[i].dis,&a[i].fuel);
    }
    a[n].dis=0;
    a[n].fuel=0;
    sort(a,a+(n+1));
//    qsort(a,n,sizeof(a),comp);
    scanf("%d %d",&dis,&fuel);
    i=0;k=0;cur_in=0;
    while(i<=n){
      while(i<=n && (dis - a[i].dis <= fuel)){
    fuel -= (dis-a[i].dis);
    dis = a[i].dis;
        insert(a[i].fuel);
    i++;
      }
      if(i<=n){
        int temp = dmax();
    if(temp==-1){
      k=-1;
      break;
    }
    fuel += temp;
        k++;
      }
    }
    printf("%d\n",k);
  }
  return 0;
}
