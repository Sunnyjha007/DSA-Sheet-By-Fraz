class Solution{
    private:
    void solve(vector<vector<int>>&board,vector<string>&ans,vector<vector<int>>&visited,string path,int row,int col,int n){
        if(row==n-1&&col==n-1){
            ans.push_back(path);
        }
        visited[row][col] = 1;
        if(row-1>=0&&col>=0&&row-1<n&&col<n&&visited[row-1][col]==0&&board[row-1][col]==1)solve(board,ans,visited,path+'U',row-1,col,n);
        if(row+1<n&&row+1>=0&&col>=0&&col<n&&visited[row+1][col]==0&&board[row+1][col]==1)solve(board,ans,visited,path+'D',row+1,col,n);
        if(row>=0&&row<n&&col+1>=0&&col+1<n&&visited[row][col+1]==0&&board[row][col+1]==1)solve(board,ans,visited,path+'R',row,col+1,n);
        if(row<n&&row>=0&&col-1>=0&&col-1<n&&visited[row][col-1]==0&&board[row][col-1]==1)solve(board,ans,visited,path+'L',row,col-1,n);
        visited[row][col] = 0;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &board, int n) {
        if(board[0][0]==0)return {};
        string path = "";
        vector<string> ans;
        vector<vector<int>> visited(n,vector<int>(n,0));
        solve(board,ans,visited,path,0,0,n);
        return ans;
        }
};
