class Solution {
public:
//traverse on each element of this matrix so O(m*n)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size(),size = m*n,k=0,rs=0,re=m-1,cs=0,ce=n-1;
        vector<int> ans;
        while(k<size){
            for(int i=cs;i<=ce&&k<size;i++){
                ans.push_back(matrix[rs][i]);k++;
            }rs++;
            for(int i=rs;i<=re&&k<size;i++){
                ans.push_back(matrix[i][ce]);k++;
            }ce--;
            for(int i=ce;i>=cs&&k<size;i--){
                ans.push_back(matrix[re][i]);k++;
            }re--;
            for(int i=re;i>=rs&&k<size;i--){
                ans.push_back(matrix[i][cs]);k++;
            }cs++;
        }
        return ans;
    }
};
