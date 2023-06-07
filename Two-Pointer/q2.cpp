class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(),mid=0,start=0,end=n-1;
        while(mid<=end){
            switch(nums[mid]){
            case 0:
                swap(nums[start],nums[mid]);
                start++;mid++;break;
            case 1:
                mid++;break;
            case 2:
                swap(nums[mid],nums[end]);
                end--;break;
            }  
        }
    }
};
