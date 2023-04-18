//tle -> dp
class Solution {
public:
    int solve(vector<int>& cardPoints,int si,int ei,int k){
        if(k==0)return 0;
        return max(cardPoints[si]+solve(cardPoints,si+1,ei,k-1),cardPoints[ei]+solve(cardPoints,si,ei-1,k-1));
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
       int n = cardPoints.size();
        if(k>=n){
            int sum=0;
            for(int i=0;i<n;i++)sum+=cardPoints[i];
            return sum;
        }else{
            return solve(cardPoints,0,n-1,k);
        }
    }
};
//prefix-sum
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> front(k+1,0);
        vector<int> back(k+1,0);
        front[0] = 0,back[k]= 0;
        for(int i=1;i<=k;i++){
            front[i] = front[i-1] + nums[i-1];
            back[k-i] = back[k-i+1] + nums[n-i];
        }
        int ans = max(front[k],back[0]);
        for(int i=0;i<=k;i++){
            ans = max(ans,front[i] + back[i]);
        }
        return ans;
    }
};
//observation
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(),sum = 0,ans=0;
        for(int i=n-k;i<n;i++){
            sum+= cardPoints[i];
        }
        ans = sum;
        for(int i=0;i<k;i++){
            sum-=cardPoints[n-k+i];
            sum+=cardPoints[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};
