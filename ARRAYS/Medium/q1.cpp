class Solution {
  //O(nlogn)
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int j = 0;
        for(int i=1;i<n;i++){
            if(intervals[j][1]>=intervals[i][0]){
                intervals[j][1] = max(intervals[j][1],intervals[i][1]);
            }else{
                j++;
                intervals[j] = intervals[i];
            }
        } 
        intervals.resize(j+1);
        return intervals;
    }
};
