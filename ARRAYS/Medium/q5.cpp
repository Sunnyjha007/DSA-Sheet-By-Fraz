class Solution {
public:
//   O(n)&&O(n)
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0,ans = 0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
            // if(sum==k)ans++;
            if(mp.count(sum-k))ans+= mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};

/*
O(brute force n^3)
int n = nums.size();
        int ans = 0;
        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               v.insert(v.end(),nums.begin()+i,nums.begin()+j+1);v.push_back(INT_MAX);
            }
            
        }
        for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
        return 9;
*/
