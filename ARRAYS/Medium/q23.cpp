class Solution {
private:
void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int> v,int idx){
    if(idx>=nums.size()){
        ans.push_back(v);
        return;
    }
    solve(nums,ans,v,idx+1);
    v.push_back(nums[idx]);
    solve(nums,ans,v,idx+1);
    v.pop_back();
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int n = nums.size();
       vector<vector<int>> ans;
       vector<int> v;
       solve(nums,ans,v,0);
       return ans;
    }
};
