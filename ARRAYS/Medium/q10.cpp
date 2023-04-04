//time complexity -> O(m*n*4^(m*n))
//space complexity -> O(m*n) + O(word.size()) - > O(m*n)
class Solution {
private:
bool isSafe(int r,int c,int m,int n){
    return (r>=0&&c>=0&&r<m&&c<n);
}
bool solve(vector<vector<char>>& board, string word,int r,int c,vector<int>& direction,int idx,vector<vector<int>>& visited){
    if(board[r][c]==word[idx]){
        visited[r][c] = 1;
        if(idx==word.size()-1)return true;
        // cout<<word[idx]<<" ";
        for(int i=0;i<4;i++){
            int nr = r + direction[i];
            int nc = c + direction[i+1];
            if(isSafe(nr,nc,board.size(),board[0].size())&&!visited[nr][nc]){
                // cout<<word[idx]<<" ";
                if(solve(board,word,nr,nc,direction,idx+1,visited))return true;
            }
        }
    visited[r][c] = 0;
    return false;
    }
    return false;   
}
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
        vector<int> direction;
        direction = {0,1,0,-1,0};
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    if(solve(board,word,i,j,direction,0,visited))return true;
            }
        }
        return false;
    }
};
