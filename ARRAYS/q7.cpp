class Solution {
public:
// O(n)
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(),rsum=0,lsum=0;
        int sum = accumulate(nums.begin(),nums.end(),0);
        rsum=sum;
        for(int i=0;i<n;i++){
            rsum-=nums[i];
            if(rsum==lsum)return i;
            lsum+= nums[i];
        }
        return -1;
    }
};
