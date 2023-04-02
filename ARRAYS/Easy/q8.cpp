class Solution {
public:
    O(n)&&O(1)
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
O(nlogn)
class Solution {
private:
int count(vector<int>& nums,int num,int si,int ei){
    int cnt = 0;
    for(int i=si;i<=ei;i++){
        if(nums[i]==num)cnt++;
    }
    return cnt;
}
int solve(vector<int>& nums,int si,int ei){
    if(si==ei)return nums[si];
    int mid = si + (ei-si)/2;
    int leftmajority = solve(nums,si,mid);
    int rightmajority = solve(nums,mid+1,ei);
    if(leftmajority==rightmajority)return leftmajority;
    int leftcnt = count(nums,leftmajority,si,mid);
    int rightcnt = count(nums,rightmajority,mid+1,ei);
    return leftcnt>rightcnt?leftmajority:rightmajority;
}
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size();
       return solve(nums,0,n-1);
    }
};
*/


/*
O(nlogn)
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
O(n)&&o(n)
int majorityElement(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int,int> mp;
       for(int i=0;i<n;i++)mp[nums[i]]++;
       for(auto it: mp)if(it.second>(n/2))return it.first;
       return -1;
    }
*/

