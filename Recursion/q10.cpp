class Solution {
private:
void solve(int k,int n,int idx,int currsum,vector<int>& nums,vector<vector<int>>& ans,vector<int>& v){
    if(k==v.size()){
        if(currsum==n){
            ans.push_back(v);
            return;
        }
        if(currsum>n)return;
    }
    if(idx>=nums.size())return;
    //non-pick
     solve(k,n,idx+1,currsum,nums,ans,v);
    //pick
    v.push_back(nums[idx]);
    solve(k,n,idx+1,currsum+nums[idx],nums,ans,v);
    v.pop_back();
       
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        solve(k,n,0,0,nums,ans,v);
        return ans;
    }
};


class Solution {
private:
void solve(int k,int n,int idx,int currsum,vector<vector<int>>& ans,vector<int> v){
    if(v.size()>k||currsum>n)return;
        if(v.size()==k&&currsum==n){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<=9;i++){
            v.push_back(i);
            solve(k,n,i+1,currsum+i,ans,v);
            v.pop_back();
        }
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(k,n,1,0,ans,v);
        return ans;
    }
};
