class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(),si=0,ei=0,sum=0,ans=1e9;
        while(ei<n){
            sum+=nums[ei];
            if(sum<target)ei++;
            else{
                while(sum>=target){
                    ans = min(ans,ei-si+1);
                    sum-=nums[si];si++;
                }
                ei++;
            }
        }
        return ans==1e9?0:ans; 
    }
};
