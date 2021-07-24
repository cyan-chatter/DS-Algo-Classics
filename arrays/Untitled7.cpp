 int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        int currnum=nums[0],currsize=1;
        for(int i=1;i<n;i++){
            if(nums[i]==currnum and currsize<2){
                currsize++;
                continue;
            }
            if(nums[i]==currnum and currsize>=2){
                cout<<"*";
                nums.erase(nums.begin()+i);
                i--;
                n--;
            }else{
                currnum=nums[i];
                currsize=1;
            }
        }
        return n;
  }
