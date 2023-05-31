class Solution {
private:
void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& v,int idx){
    ans.push_back(v);
    for(int i=idx;i<nums.size();i++){
        if(i!=idx&&nums[i]==nums[i-1])continue;
        v.push_back(nums[i]);
        solve(nums,ans,v,i+1);
        v.pop_back();
    }
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums,ans,v,0);
        return ans;
    }
};
