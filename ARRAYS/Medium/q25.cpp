class Solution {
private:
bool solve(vector<int>& nums,vector<int>& dp,int idx){
    if(idx>=nums.size()-1)return true;
    if(dp[idx]!=-1)return dp[idx];
    for(int i=1;i<=nums[idx];i++){
        if(solve(nums,dp,idx+i))return dp[idx] = 1;
    }
    return dp[idx] = 0;
}
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,0);
    }
};
