int lenOfLongSubarr(int arr[],  int n, int k){ 
        int sum=0,si=0,ei=0,ans=0;
        unordered_map<int,int> mp;
        while(ei<n){
            sum+=arr[ei];
            if(sum==k){
                ans = max(ans,ei+1);
            }
            if(mp.find(sum)==mp.end())mp[sum] = ei;
            if(mp.find(sum-k)!=mp.end()){
                ans = max(ans,ei-mp[sum-k]);
            }
            ei++;
        }
        return ans;
    } 
