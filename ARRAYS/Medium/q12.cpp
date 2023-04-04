//naive approach
class Solution {
private:
bool isSafe(int r,int c,int m,int n){
    return (r>=0&&c>=0&&r<m&&c<n);
}
void solve(vector<vector<int>>& board,vector<vector<int>>& direction,int r,int c,vector<vector<int>>& ans){
    int cnt = 0;
    for(int i=0;i<8;i++){
        int nr = r + direction[i][0];
        int nc = c + direction[i][1];
        if(isSafe(nr,nc,board.size(),board[0].size())&&board[nr][nc]==1)cnt++;
    }
    if(board[r][c]==1&&cnt<2)ans[r][c] = 0;
    if(board[r][c]==1&&(cnt==2||cnt==3))ans[r][c] = 1;
    if(board[r][c]==1&&cnt>3)ans[r][c] = 0;
    if(board[r][c]==0&&cnt==3)ans[r][c]=1;
}
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(),n = board[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> direction;
        direction = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                solve(board,direction,i,j,ans);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)board[i][j] = ans[i][j];
        }
    }
};
//first follow-up part
class Solution {
private:
bool isSafe(int r,int c,int m,int n){
    return (r>=0&&c>=0&&r<m&&c<n);
}
void solve(vector<vector<int>>& board,vector<vector<int>>& direction,int r,int c,vector<vector<int>>& ans){
    int cnt = 0;
    for(int i=0;i<8;i++){
        int nr = r + direction[i][0];
        int nc = c + direction[i][1];
        if(isSafe(nr,nc,board.size(),board[0].size())&&board[nr][nc]==1)cnt++;
    }
    if(board[r][c]==1&&cnt<2)ans[r][c] = 0;
    if(board[r][c]==1&&(cnt==2||cnt==3))ans[r][c] = 1;
    if(board[r][c]==1&&cnt>3)ans[r][c] = 0;
    if(board[r][c]==0&&cnt==3)ans[r][c]=1;
}
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(),n = board[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> direction;
        direction = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                solve(board,direction,i,j,ans);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)board[i][j] = ans[i][j];
        }
    }
};
