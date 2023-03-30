class Solution {
  //O(n)
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
                int n = nums.size();
        vector<int> v;

        for(int i=0;i<n;i++){
            sum+= nums[i];
            v.push_back(sum);
        }
        return v;
    }
};
