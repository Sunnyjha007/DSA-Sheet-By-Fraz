class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            int val = abs(nums[i]) - 1;
            if(nums[val]>0)nums[val]*=-1;
            else v.push_back(val + 1);
        }
        return v;
    }
};
//extra space
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> index(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(index[nums[i]-1]>0){
                ans.push_back(nums[i]);
            }
            index[nums[i]-1]++;
        }
        return ans;
    }
};
