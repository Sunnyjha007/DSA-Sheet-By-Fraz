class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans = {{}};
        for(int i=0;i<n;i++){
            int size = ans.size();
            for(int j=0;j<size;j++){
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
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
