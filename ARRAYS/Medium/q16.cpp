class Solution {
private:
//t.c.-> O(n^m) s.c.-> O(m) recursion call stack
void solve(vector<int>& candidates, int target, vector<vector<int>>& answer,vector<int> temp,int idx,int curr_sum){
    if(idx>=candidates.size())return;
    if(target<curr_sum)return;
    if(curr_sum==target){
        answer.push_back(temp);
        return;
    }
    //non-take
    solve(candidates,target,answer,temp,idx+1,curr_sum);
    //take
    temp.push_back(candidates[idx]);
    solve(candidates,target,answer,temp,idx+1,curr_sum+candidates[idx]);
    temp.pop_back();
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> temp;
        solve(candidates,target,answer,temp,0,0);
        return answer;
    }
};
