class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n = nums.size();
       for(int i=0;i<n;i++){
           int ele = nums[i];
           if(ele>=1&&ele<=n){
                int idx = ele - 1;
               if(nums[idx]!=ele){
                    swap(nums[idx],nums[i]);
                    i--;
               }   
           }
       }
       for(int i=0;i<n;i++)if(i+1!=nums[i])return i+1;
       return n+1;
    }
};


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        for(int i=0;i<n;i++){
            if(nums[i]==ans)ans++;
            if(ans<nums[i])break;
        }
        return ans;
    }
};
