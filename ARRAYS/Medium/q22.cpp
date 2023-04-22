class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)mp[nums[i]]++;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==0||(k==0)&&mp[nums[i]]<=1)continue;
            if(k==0){
                ans++;mp[nums[i]] = 0;continue;
            }
            if(mp[nums[i]+k]>0)ans++;
            if(mp[nums[i]-k]>0)ans++;
            mp[nums[i]] = 0;
        }
        return ans;
    }
};
