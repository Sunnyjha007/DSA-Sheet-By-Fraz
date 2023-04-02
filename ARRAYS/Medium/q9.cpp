class Solution {
public:
  //transpose and then reverse the each row->O(n^2)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(i==j)continue;
                 swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)reverse(matrix[i].begin(),matrix[i].end());
    }
};
