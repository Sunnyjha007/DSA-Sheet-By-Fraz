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
bool solve(vector<int>& nums,vector<int>& dp){
    dp[nums.size()-1] = 1;
    for(int i=nums.size()-2;i>=0;i--){
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size()&&dp[i+j]==1){
                dp[i] = 1;break;
            }
        }
    }
    return dp[0];
}
bool solve(vector<int>& nums){
    int n = nums.size();
    int max_reach = 0;
    for(int i=0;i<n;i++){
        if(max_reach<i)return false;
        max_reach = max(max_reach,i+nums[i]);
    }
    return true;
}
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n,-1);
        // return solve(nums,dp,0);
        // vector<int> dp(n,0);
        // return solve(nums,dp);
        return solve(nums);
    }
};
