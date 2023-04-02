class Solution {
    //t.c. -> o(nlogn)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
      vector<pair<int,int>> v;
      for(int i=0;i<n;i++)v.push_back({nums[i],i});
      sort(v.begin(),v.end());
      int i=0,j=n-1;
      while(i<j){
          int sum = v[i].first + v[j].first;
          if(sum==target)return {v[i].second,v[j].second};
          else if(sum>target)j--;
          else i++;
      }
      return {-1,-1};
    }
};
/*
O(n), O(n^2)worst case - t.c.
o(n) - s.c.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
       unordered_map<int,int> mp;
       for(int i=0;i<n;i++){
           if(mp.count(target-nums[i]))return {mp[target-nums[i]],i};
           mp[nums[i]] = i;
       }
       return {-1,-1};
    }
};
*/

/*
class Solution {
public:
O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               if(nums[i]+nums[j]==target)return {i,j};
           }
       }
       return {-1,-1};
    }
};
*/
