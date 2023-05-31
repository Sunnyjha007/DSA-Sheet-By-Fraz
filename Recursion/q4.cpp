class Solution {
private:
// void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& v,vector<int>& visited){
//     if(v.size()==nums.size()){
//         ans.push_back(v);
//         return;
//     }
//     for(int i=0;i<nums.size();i++){
//         if(!visited[i]){
//             visited[i] = true;
//             v.push_back(nums[i]);
//             solve(nums,ans,v,visited);
//             v.pop_back();
//             visited[i] = false;
//         }
//     }
// }
// void solve(vector<int>& nums,vector<vector<int>>& ans,int idx){
//     if(idx>=nums.size()){
//         ans.push_back(nums);
//         return;
//     }
//     for(int i = idx;i<nums.size();i++){
//         swap(nums[idx],nums[i]);
//         solve(nums,ans,idx+1);
//         swap(nums[idx],nums[i]);
//     }
// }
void solve(vector<int>& nums,vector<vector<int>>& ans){
    sort(nums.begin(),nums.end());
    ans.push_back(nums);
    while(next_permutation(nums.begin(),nums.end())){
        ans.push_back(nums);
    }
    return;
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        solve(nums,ans);
        // vector<int> v;
        // vector<int> visited(n,0);
        // // solve(nums,ans,0);
        // solve(nums,ans,v,visited);
        return ans;
    }
};
