class Solution {
private:
void solve(vector<string>& arr,int idx,int &ans,vector<int>& freq){
    if(idx>=arr.size()){
       ans = max(ans,accumulate(freq.begin(),freq.end(),0));
        return;
    }
    //non-pick
     solve(arr,idx+1,ans,freq);
     //pick
    int cnt = 0,i=0;
    for(i=0;i<arr[idx].size();i++){
        if(freq[arr[idx][i]-'a']){
            cnt=1;
            break;
        }
        freq[arr[idx][i]-'a']=1;
    }
    if(cnt==1){
        for(--i;i>=0;i--)freq[arr[idx][i]-'a']=0;
        return;
    }
    solve(arr,idx+1,ans,freq);
    for(int j=0;j<arr[idx].size();j++){
        freq[arr[idx][j]-'a']=0;
    }
     
}
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
         vector<int> freq(26,0);
         int ans = 0;
        solve(arr,0,ans,freq);
        return ans;
    }
};
