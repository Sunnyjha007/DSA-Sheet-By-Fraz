#define p pair<int,int>
struct myComp {
    constexpr bool operator()(pair<int, int> const& a,pair<int, int> const& b)const noexcept{
        // return a.second > b.second;
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<p,vector<p>,myComp> pq;
        int n = nums.size();
        vector<int> ans;
        vector<int> visited(n,0);
        int maxi = -1e9, si=0,ei=0;
        while(ei<n){
             pq.push({nums[ei],ei});
            if(ei-si+1==k){
                // if(!visited[pq.top().second])ans.push_back(pq.top());
                while(!pq.empty()&&visited[pq.top().second])pq.pop();
                ans.push_back(pq.top().first);
                if(nums[si]==pq.top().first)pq.pop();
                visited[si] = 1;
                si++;
            }
            ei++;
        }
        return ans;
    }
};
