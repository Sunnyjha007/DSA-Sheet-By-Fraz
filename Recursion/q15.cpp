class Solution {
private:
//t.c. -> O(m*n*4^len.)
bool isSafe(int r,int c,int m,int n){
    return (r>=0&&c>=0&&r<m&&c<n);
}
bool dfs(vector<vector<char>>& board,string word,vector<vector<int>>& visited,
vector<int>& direction,int sr,int sc,int idx){
    if(idx==word.size())return true;
    if(!isSafe(sr,sc,board.size(),board[0].size())||visited[sr][sc]||board[sr][sc]!=word[idx])return false;
    visited[sr][sc] = 1;
    for(int i=0;i<4;i++){
        int nr = sr + direction[i];
        int nc = sc + direction[i+1];
        if(dfs(board,word,visited,direction,nr,nc,idx+1))return true;
    }
    visited[sr][sc] = 0;
    return false;
}
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> direction = {0,1,0,-1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,visited,direction,i,j,0))return true;
                }
            }
        }
        return false;
    }
};
