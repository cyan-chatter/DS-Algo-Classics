class Solution {  
    map<string,int> dp;
    
    int getMax(vector<int> v, int l, int r){ 
        string key1 = to_string(l);  
        string key2 = to_string(r);
        string key = key1 + '-';
        key = key + key2;
        auto it = dp.find(key);
        int ans = 0;
        if(it == dp.end()){
            for(int i=l+1; i<r; ++i){
                int point = v[i]*v[l]*v[r];
                ans = max( ans, (point + getMax(v,l,i) + getMax(v,i,r)) );
            }
            dp.insert(pair<string,int>(key,ans));
        }else{
            ans = it->second;
        }
        return ans;   
    }
    
    
public:
    int maxCoins(vector<int>& nums) {
       int len = nums.size();
        if(len == 0){
            return 0;
        }
        if(len == 1){
            return nums[0];
        }
        
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        len = len + 2;
        int ans = getMax(nums, 0, len-1);
        return ans;
    }
    
};
//4 2 8   
//3 6 1 4 0 9 3 5 2 7  

