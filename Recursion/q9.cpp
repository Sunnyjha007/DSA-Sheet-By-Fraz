class Solution {
private:
void solve(vector<int>&candidates,int idx,int currsum,int target,vector<vector<int>>&ans,vector<int>&v){
    if(currsum>target)return;
        if(currsum==target){
            ans.push_back(v);
            return;
        }
    for(int i=idx;i<candidates.size();i++){
        if(i!=idx&&candidates[i]==candidates[i-1])continue;
        v.push_back(candidates[i]);
        solve(candidates,i+1,currsum+candidates[i],target,ans,v);
        v.pop_back();
    }
}
public:
//t.c -> O((2^n)*k), s.c. -> O(x)->longest combinations
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,0,target,ans,v);
        return ans;
    }
};
