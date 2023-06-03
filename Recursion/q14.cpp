class Solution {
private:
void dfs(vector<vector<int>>& image,vector<int>& direction,int sr,
int sc,int oldColor,int color,vector<vector<int>>& visited){
if(sr<0||sc<0||sr>=image.size()||sc>=image[0].size()||visited[sr][sc]||image[sr][sc]!=oldColor)return;
    image[sr][sc] = color;
    visited[sr][sc] = 1;
    for(int i=0;i<4;i++){
        int nr = sr + direction[i];
        int nc = sc + direction[i+1];
        dfs(image,direction,nr,nc,oldColor,color,visited);
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(),n = image[0].size();
        int oldColor = image[sr][sc];
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> direction = {0,1,0,-1,0};
         dfs(image,direction,sr,sc,oldColor,color,visited);
         return image;
    }
};
