class Solution {
    
    int helper(vector<int> a,int i){
            a.erase(a.begin()+i);
            int mx = (a[1] * a[0]);
            if(a[0]>=a[1]){
                mx += a[0];
            }else{
                mx += a[1];
            }
            return mx;
    }
    
public:
    int maxCoins(vector<int>& a) {
        int n = a.size();
        int x=0;
        if(n==0){
            return 0;
        }
        if(n==1){
            return a[0];
        }
        
        for(int i=0; i<(a.size()); ++i){
                if(a[i] == 0){
                    a.erase(a.begin()+i);
                }
        }
        
        for(int i=0; i<(a.size()); ++i){
                if(a[i] == 1){
                    if(i==0){
                        x += a[1];
                    }
                    else if(i==n-1){
                        x += a[n-2];
                    }
                    else{
                        x += a[i-1] * a[i+1];
                    }
                    a.erase(a.begin()+i);
                }
        }
        
        n = a.size();
        
        if(n==0){
            return x;
        }
        if(n==1){
            x += a[0];
            return x;
        }
        
        
        if(n==2){
            x += (a[1] * a[0]);
            if(a[0]>=a[1]){
                x += a[0];
            }else{
                x += a[1];
            }
            return x;
        }
        while(n>3){
            int min = 1;
            for(int i=1; i<(a.size()-1); ++i){
                if(a[min]>a[i]){
                    min = i;
                }
            }
            x += a[min]*a[min-1]*a[min+1];
            a.erase(a.begin()+min);
            --n;
        }
       if(n == 3){
           int x1 = helper(a,0);
           int x2 = helper(a,1);
           int x3 = helper(a,2);
           x1 += a[0]*a[1];
           x2 += a[0]*a[1]*a[2];
           x3 += a[1]*a[2];
           int max3 = max(x1,max(x2,x3));
           x += max3;
           return x;
       }
        
        return 0;
    }
};
//4 2 8   //32 104 28
//3 6 1 4 0 9 3 5 2 7  


//7740
//189344
