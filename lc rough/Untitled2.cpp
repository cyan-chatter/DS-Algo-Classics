class Solution {
public:
    
   int binarySearchMod(vector<int> A, int N, int key)
{
    int low = 0, high = N - 1;
    int c = 0;
    if(key == 0){
        return 0;
    }   
    while (low <= high)
    {
        int mid = (low + high)/2;   
        if (key == A[mid]){
            ++c;
            continue;
        }
        if (key < A[mid])
            high = mid - 1;
        else if(key > A[mid])
            low = mid + 1;
    }
     return c;
}
    
    int fact(int n){ 
		int f = 1;
		while(n != 1){
			f *= n;
			--n;
		}
		return f;
	}
    
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        if(n == 0 || n == 1){
            return 0;
        }
        int c0 = 0, p0 = 0;
        for(int i=0; i<n; ++i){
            if(time[i] == 0){
                ++c0;  
            }
            if(time[i]%60 == 0 && time[i] != 0){
                ++p0;
            }
            time[i] = time[i]%60;
        }
        if(c0 == n){
            return 0;
        }
        p0 = fact(p0);
        sort(time.begin(), time.end());
        int c = 0;
        for(int i=0; i<n; ++i){
           c += binarySearchMod(time, n, 60 - time[i]);
        }
        c += p0;
        return c;
    }
};
