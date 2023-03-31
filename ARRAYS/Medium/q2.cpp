class Solution {
//   O(nlogn)
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(),nums.end());
      vector<vector<int>> v;
      for(int i=0;i<n-2;i++){
          if(i>0&&nums[i]==nums[i-1])continue;
          int left = i+1,right = n-1;
          while(left<right){
              int sum = nums[i] + nums[left] + nums[right];
              if(sum<0)left++;
              else if(sum>0)right--;
              else{
                  v.push_back({nums[i],nums[left],nums[right]});
                  int left_val = nums[left];
                  int right_val = nums[right];
                  while(left<n&&left_val==nums[left])left++;
                  while(right>=0&&right_val==nums[right])right--;
              }
          }
      }
      return v; 
    }
};


//3-sum-closet
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
