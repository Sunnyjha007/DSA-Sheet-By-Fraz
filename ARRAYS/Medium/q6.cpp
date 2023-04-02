class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i>0&&nums[i-1]>=nums[i])i--; // o(n)
        if(i==0){reverse(nums.begin(),nums.end());return;} //O(n)
        int j = n-1;
        while(j>0&&nums[i-1]>=nums[j])j--;  //O(n)
        swap(nums[i-1],nums[j]);
        reverse(nums.begin()+i,nums.end()); //O(n-i)->O(n)

    }
};
//brute force generate all permutation -> return just next of given nums  
//O(n!) to compute permutation
