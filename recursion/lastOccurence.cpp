 #include<iostream>
using namespace std;

int lastOcc(int *a, int n, int &key){
    if(n==0){
        return -1;
    }
    if(a[n-1] == key){
        return n-1;
    }
    int mila = lastOcc(a,n-1,key);
    return mila;
}

int lastOcc2(int *a, int n, int &key){
    if(n==0){
        return -1;
    }
    int mila = lastOcc2(a+1,n-1,key);
    if(mila != -1){
        mila++;
    }else{
        if(a[0] == key){
            return 0;
        }
    }
    return mila;
}

void lastOcc3(int *a, int s, int e, int &key, int &hold){
    if(s == e){
        return;
    }
    if(a[s] == key){
        hold = s;
    }
    lastOcc3(a,s+1,e,key,hold);    
}


int main(){

    int ar[] = {2,5,3,6,3,5,34,4,4,3,5,3,6,7,55,34,6,54,8};
    int key = 34;
    int n = sizeof(ar)/sizeof(int);
    int hold = -1;
    lastOcc3(ar,0,n,key,hold);
    cout<<hold;
    return 0;
}