class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int hare = nums[0];
        int tortoise = nums[0];
        hare = nums[nums[hare]];
        tortoise = nums[tortoise];
        while(hare!=tortoise){
            hare = nums[nums[hare]];
    		tortoise = nums[tortoise];
        }
        hare = nums[0];
        	while(hare!=tortoise){
    		hare = nums[hare];
    		tortoise=nums[tortoise];
    	}
    	return tortoise;
    }
};
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[abs(nums[i])] = -1*nums[abs(nums[i])];
            if(nums[abs(nums[i])]>0)return abs(nums[i]);
        }
        return -1;
    }
};
*/
