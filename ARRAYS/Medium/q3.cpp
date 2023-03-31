//zero optimised 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }else{
                product*=nums[i];
            }
        }
        vector<int> ans(n,0);
        if(cnt>1)return ans;
        if(cnt==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0)ans[i] = product;
            }
        }else{
            for(int i=0;i<n;i++){
                ans[i] = product/nums[i];
            }
        }
        return ans;
    }
};
//prefix-without space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,1);
        int curr = 1;
        for(int i=0;i<n;i++){
            v[i]*=curr;
            curr*=nums[i]; 
        }
        curr=1;
        for(int i=n-1;i>=0;i--){
            v[i]*=curr;
            curr*=nums[i];
        }
        return v;
    }
};
//prefix with space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,0),right(n,0);
        int product = nums[0];
        left[0] = 1;
        for(int i=1;i<n;i++){
            left[i] = product;
            product*= nums[i];
        }
        product = nums[n-1];
        right[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            right[i] = product;
            product*= nums[i];
        }
        for(int i=0;i<n;i++)nums[i] = left[i]*right[i];
        return nums;
    }
};
//o(n^2) -> 2 loop and if i==j then continue else calculate product
