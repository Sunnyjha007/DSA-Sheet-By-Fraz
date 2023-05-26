class Solution {
private:
vector<int> NSL(vector<int>& nums){
    int n = nums.size();
    vector<int> v;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        if(st.empty())v.push_back(-1);
        else if(!st.empty()&&st.top().first<nums[i])v.push_back(st.top().second);
        else {
            while(!st.empty()&&st.top().first>=nums[i])st.pop();
            if(st.empty())v.push_back(-1);
            else v.push_back(st.top().second);
        }
        st.push({nums[i],i});
    }
    return v;
}
vector<int> NSR(vector<int>& nums){
    int n = nums.size();
    vector<int> v;
    stack<pair<int,int>> st;
    for(int i=n-1;i>=0;i--){
        if(st.empty())v.push_back(n);
        else if(!st.empty()&&st.top().first<nums[i])v.push_back(st.top().second);
        else {
            while(!st.empty()&&st.top().first>=nums[i])st.pop();
            if(st.empty())v.push_back(n);
            else v.push_back(st.top().second);
        }
        st.push({nums[i],i});
    }
    reverse(v.begin(),v.end());
    return v;
}
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int width = right[i] - left[i]-1;
            ans = max(ans,heights[i]*width);
        }
        return ans;
    }
};
