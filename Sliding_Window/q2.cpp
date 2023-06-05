class Solution {
public:
    int longestOnes(vector<int>& nums, int k){
        int n = nums.size(),si=0,ei=0,cnt=0,ans=0;
        while(ei<n){
            if(nums[ei]==0)cnt++;
            if(cnt>k){
                if(nums[si]==0)cnt--;
                si++;
            }
            ei++;
        }
        return (ei-si);
    }
};
