class Solution {
public:
//   O(n)-> 2 pointer approach
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int si = 0,ei = n-1;
        vector<int> v(n,0);
        int k = n-1;
        while(si<=ei){
            if(abs(nums[si])<=abs(nums[ei])){
                v[k--] = nums[ei]*nums[ei];
                ei--;
            }else{
                v[k--] = nums[si]*nums[si];
                si++;
            }
        }
        return v;
    }
};
//brute force will be square and then sort the array -> o(nlogn)
