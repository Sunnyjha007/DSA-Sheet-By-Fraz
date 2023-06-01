class Solution {
private:
void solve(vector<int>&candidates,int idx,int currsum,int target,vector<vector<int>>&ans,vector<int>&v){
    if(idx>candidates.size())return;
    if(currsum>target)return;
    if(idx==candidates.size()){
        if(currsum==target)ans.push_back(v);
        return;
    }
    //non-pick
    solve(candidates,idx+1,currsum,target,ans,v);
    //pick
    v.push_back(candidates[idx]);
    solve(candidates,idx,currsum+candidates[idx],target,ans,v);
    v.pop_back();
}
public:
//t.c.-> O((2^t)*k) s.c.-> O(k*x) recursion call stack
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(candidates,0,0,target,ans,v);
        return ans;
    }
};
