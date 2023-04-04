// time complexity -> O(nlogn)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0;i<n-2;i++){
            int left = i+1,right = n-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum==target)return target;
                if(abs(sum-target)<abs(ans-target))ans = sum;
                if(sum>target)right--;
                else left++;
            }
        }
        return ans;
    }
};
