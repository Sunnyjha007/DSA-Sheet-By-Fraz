class Solution {
private:
int solve(vector<int>& prices,int idx,int trans,int buy,vector<vector<vector<int>>>& dp){
    if(idx>=prices.size()||trans>=2)return 0;
    if(dp[idx][trans][buy]!=-1)return dp[idx][trans][buy];
    if(buy){
        return dp[idx][trans][buy] = max(-prices[idx] + solve(prices,idx+1,trans,!buy,dp),solve(prices,idx+1,trans,buy,dp));
    }else{
        return dp[idx][trans][buy] = max(prices[idx]+solve(prices,idx+1,trans+1,!buy,dp),solve(prices,idx+1,trans,buy,dp));
    }
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),trans = 0,buy = 1;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices,0,trans,buy,dp);
    }
};
