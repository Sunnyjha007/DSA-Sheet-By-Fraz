class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();
    }
};
/*
//best solution -> O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int idx=0;
        for(int i=1;i<n;i++){
            if(nums[idx]!=nums[i]){
                idx++;
                nums[idx] = nums[i];
            }
        }
        return idx+1;
    }
};
*/
