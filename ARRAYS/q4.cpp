class Solution {
public:
// O(n)
    void moveZeroes(vector<int>& nums) {
       int n = nums.size();
       int idx = 0,cnt=0;
       for(int i=0;i<n;i++){
           if(nums[i]==0){
               cnt++;
               continue;
           }else nums[idx++] = nums[i];
       }
       for(int j = 0;j<cnt;j++)nums[idx++] = 0;
    }
};
