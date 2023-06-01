class Solution {
private:
bool solve(vector<int>& nums,vector<int>& visited,int k,int idx,int cs,int target){
    if(k==0)return true;
    if(cs>target)return false;
    if(cs==target)return solve(nums,visited,k-1,0,0,target);
    for(int i=idx;i<nums.size();i++){
        if(visited[i])continue;
            visited[i] = 1;
            cs+=nums[i];
            if(solve(nums,visited,k,i+1,cs,target))return true;
            cs-=nums[i];
            visited[i] = 0;
            if(cs==0)break;
    }
    return false;
}
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k)return false;
        int target = sum/k;
        vector<int> visited(nums.size(),0);
        return solve(nums,visited,k,0,0,target);
    }
};
