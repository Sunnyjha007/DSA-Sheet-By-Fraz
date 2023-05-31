class Solution {
private:
// void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& v,int k,int idx){
//     if(idx>=nums.size()){
//         if(v.size()==k){
//             ans.push_back(v);
//         }
//         return;
//     }
//     //non-pick
//     solve(nums,ans,v,k,idx+1);
//     v.push_back(nums[idx]);
//     solve(nums,ans,v,k,idx+1);
//     v.pop_back();
// }
// void solve(int n,int k,vector<vector<int>>& ans,vector<int>& v,int idx){
//     if(v.size()==k){
//         ans.push_back(v);
//         return;
//     }
//     for(int i=idx;i<=n;i++){
//         v.push_back(i);
//         solve(n,k,ans,v,i+1);
//         v.pop_back();
//     }
// }
void solve(int n,int k,vector<vector<int>>& ans,vector<int>& v){
    int i=0;
    while(i>=0){
        v[i]++;
        if(v[i]>n)i--;
        else if(i==k-1)ans.push_back(v);
        else {
            i++;
            v[i] = v[i-1];
        }
    }
}
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v(k,0);
        // vector<int> nums;
        // for(int i=1;i<=n;i++)nums.push_back(i);
        // solve(nums,ans,v,k,0);
        // solve(n,k,ans,v,1);
        solve(n,k,ans,v);
        return ans;
    }
};
