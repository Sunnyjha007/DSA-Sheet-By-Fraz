class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size(),cnt=0,ele=0;
       for(int i=0;i<n;i++){
           if(cnt==0)ele = nums[i];
           if(ele==nums[i])cnt++;
           else cnt--;
       }
       return ele;
    }
};
/*
int majorityElement(vector<int>& nums) {
       int n = nums.size(),i=0;
      sort(nums.begin(),nums.end());
      while(i<n){
          if(nums[i+(n/2)]==nums[i])return nums[i];
          else {
              while(nums[i+1]==nums[i])i++;
          }
          i++;
      }
      return -1;
    }
*/
/*
int majorityElement(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int,int> mp;
       for(int i=0;i<n;i++)mp[nums[i]]++;
       for(auto it: mp)if(it.second>(n/2))return it.first;
       return -1;
    }
*/
/*
 int n = nums.size();
        int cnt=0,ele=0;
        for(int i=0;i<n;i++){
            if(cnt==0)ele = nums[i];
            if(ele==nums[i])cnt++;
            else cnt--;
        }
        return ele;
*/
