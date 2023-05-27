#define p pair<int,int>
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size(),ans = -1e9;
        priority_queue<p> pq;
        for(int i=0;i<n;i++){
             while(!pq.empty()&&(points[i][0] - pq.top().second)>k)pq.pop();
             if(!pq.empty()&&(points[i][0] - pq.top().second)<=k)ans = max(ans,(pq.top().first + points[i][0]+ points[i][1]));
            pq.push({(points[i][1]-points[i][0]),points[i][0]});
        }
        return ans;
    }
};

/*
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = -1e9,n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(points[i][0]-points[j][0])<=k){
                    ans = max(ans,points[i][1]+points[j][1]+abs(points[i][0]-points[j][0]));
                }else break;
            }
        }
        return ans;
    }
};
*/
