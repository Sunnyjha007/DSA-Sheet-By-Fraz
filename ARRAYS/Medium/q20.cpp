class Solution {
private:
// int dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,vector<int>& direction,int r,int c){
//     if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||visited[r][c]||grid[r][c]==0)return 0;
//     visited[r][c] = true;
//     int ans = 0;
//     for(int i=0;i<4;i++){
//         int nr = r + direction[i];
//         int nc = c + direction[i+1];
//         ans+= dfs(grid,visited,direction,nr,nc);
//     }
//     return (1 + ans);
// }
bool isSafe(int r,int c,int m,int n){
    return (r>=0&&c>=0&&r<m&&c<n);
}
int bfs(vector<vector<int>>& grid,vector<vector<int>>& visited,vector<int>& direction,int r,int c){
    int m = grid.size(),n=grid[0].size();
    visited[r][c] = true;
    queue<pair<int,int>> pn;
    pn.push({r,c});
    int ans = 0;
    while(!pn.empty()){
        int row = pn.front().first;
        int col = pn.front().second;
        pn.pop();
        ans++;
        for(int i=0;i<4;i++){
            int nr = row + direction[i];
            int nc = col + direction[i+1];
            if(isSafe(nr,nc,m,n)&&!visited[nr][nc]&&grid[nr][nc]==1){
                visited[nr][nc] = 1;
                pn.push({nr,nc});
            }
        }
    }
    return ans;
}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<int> direction;
        direction = {0,1,0,-1,0};
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&grid[i][j]==1){
                    int cnt = bfs(grid,visited,direction,i,j);
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
