class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int left = j+1;
                int right = n-1;
                while(left<right){
                    long long  sum = nums[i]*1ll + nums[j]*1ll + nums[left]*1ll + nums[right]*1ll;
                    if(sum>target)right--;
                    else if(sum<target)left++;
                    else{
                        ans.push_back({nums[i], nums[j], nums[left] , nums[right]});
                        int leftval = nums[left];
                        int rightval = nums[right];
                        while(left<n&&leftval==nums[left])left++;
                        while(right>=0&&rightval==nums[right])right--;
                    }
                    
                }
            }
        }
        return ans;
    }
};
