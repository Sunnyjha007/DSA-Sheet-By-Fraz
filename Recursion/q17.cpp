class Solution {
private:
//t.c.-> O(n!)&& s.c.-> O(n*n);
bool isSafe(int row,int col,int n,vector<string>& s){
    int r = row,c = col;
    while(c>=0){
        if(s[r][c]=='Q')return false;
        c--;
    }
    r = row,c = col;
    while(r>=0&&c>=0){
        if(s[r][c]=='Q')return false;
        r--;c--;
    }
    r = row,c = col;
    while(r<n&&c>=0){
        if(s[r][c]=='Q')return false;
        r++;c--;
    }
    return true;
}
void solve(vector<vector<string>>& ans,vector<string>& s,int n,int col){
    if(col==n){
        ans.push_back(s);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,n,s)){
            s[row][col] = 'Q';
            solve(ans,s,n,col+1);
            s[row][col] = '.';
        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> s(n,string(n,'.'));
        solve(ans,s,n,0);
        return ans;
    }
};
