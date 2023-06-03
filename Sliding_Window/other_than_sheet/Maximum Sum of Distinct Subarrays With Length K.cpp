class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       int n = nums.size();
       unordered_map<int,int> mp;
       long long ans = 0,si=0,ei=0,sum=0;
       for(ei=0;ei<n;ei++){
           while(si<ei&&(mp.count(nums[ei])>=1||mp.size()>=k)){
               sum-=nums[si];
               mp.erase(nums[si]);
               si++;
           }
           sum+= nums[ei];
           mp[nums[ei]]++;
           if(mp.size()==k)ans = max(ans,sum);
       }
       return ans;
    }
};
