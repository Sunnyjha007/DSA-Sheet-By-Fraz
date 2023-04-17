class Solution {
private:
    // int solve(vector<int>& nums,vector<int>& dp,int idx){
    //     if(idx>=nums.size()-1)return 0;
    //     if(nums[idx]==0)return dp[idx] = 1e9;
    //     if(dp[idx]!=1e9)return dp[idx];
    //     int ans = 1e9;
    //     for(int i=1;i<=nums[idx];i++){
    //         ans = min(ans,1+solve(nums,dp,idx+i));
    //     }
    //     return dp[idx] = ans;
    // }
    int solve(vector<int>& nums,vector<int>& dp){
        int n = nums.size();
        dp[0] = 0;
      //O(n*maxelement)
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j<n){
                    dp[i+j] = min(1+dp[i],dp[i+j]);
                }
            }
        }
        return dp[n-1];
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1e9);
        // return solve(nums,dp,0);
        return solve(nums,dp);
    }
};
