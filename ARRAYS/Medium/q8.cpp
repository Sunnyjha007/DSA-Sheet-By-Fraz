class Solution {
public:
  //2pointer approach
    int maxArea(vector<int>& height) {
        int n = height.size(),ans=0,si=0,ei=n-1;
        while(si<ei){
            ans = max(ans,(ei-si)*min(height[si],height[ei]));
            if(height[si]<height[ei])si++;
            else ei--;
        }
        return ans;
    }
};
/*
class Solution {
public:
O(n^2)->brute force
    int maxArea(vector<int>& height) {
        int n = height.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans,(j-i)*min(height[j],height[i]));
            }
        }
        return ans;
    }
};
*/
