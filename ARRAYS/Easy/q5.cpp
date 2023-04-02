class Solution {
private:
//O(2*n)&&O(2*n)
int solve(vector<int>& prices,int idx,int buy,vector<vector<int>>& dp){
    if(idx>=prices.size())return 0;
    if(dp[idx][buy]!=-1)return dp[idx][buy];
    if(buy){
        // -ve price means we are buying means we are paying so deduct
        return dp[idx][buy] = max(-prices[idx]+ solve(prices,idx+1,!buy,dp),solve(prices,idx+1,buy,dp));
    }else{
        return dp[idx][buy] = max(+prices[idx]+ solve(prices,idx+1,!buy,dp),solve(prices,idx+1,buy,dp));
    }
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),buy=1; // buy==1 means first buy then sale
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,buy,dp);
    }
};
/*
O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans =0 ;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1])ans+= prices[i] - prices[i-1];
        }
        return ans;
    }
};
*/
