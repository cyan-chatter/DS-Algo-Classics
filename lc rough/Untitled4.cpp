int removeDuplicates(vector<int>& a) {
        int n = a.size();
        int c = 0;
        int k = 0;
        int j = 0;
        int i = 0; 
        int d = 0;
        for(; i < n-2; ++i){
            if(a[i] == a[i+1] && a[i+1] == a[i+2]){
                j=i+1;
                i=i+2;
				if(i == n-1){
                    ++d;
					break;
                }
                while(i<n && a[i] == a[j]){
                    ++d;
					++i;
                }                
                c = i;
                    
					for(k=j+1; c<n; ++k, ++c){
                        //shift elements
                        a[k] = a[c];
                    }
                    
                i = j+1;
            }
            
        }
        n = n-d;
        return n;
}

