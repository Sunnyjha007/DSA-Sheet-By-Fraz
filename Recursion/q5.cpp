class Solution {
private:
void solve(vector<int> nums,vector<vector<int>>& ans,int idx){
    if(idx==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        if(i!=idx&&nums[i]==nums[idx])continue;
            swap(nums[i],nums[idx]);
            solve(nums,ans,idx+1);
    }   
}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
         solve(nums,ans,0);
         return ans;
    }
};
