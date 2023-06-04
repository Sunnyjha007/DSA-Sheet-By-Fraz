class Solution {
private:
bool isSafe(unordered_map<string,int> mp,string str,int wordSize,vector<string>& words,int m){
    // cout<<str<<" ";
    for(int i=0;i<str.size();i+=wordSize){
        string curr = str.substr(i,wordSize);
        // cout<<curr<<" ";
        if(mp[curr]==0)return false;
        else{
            mp[curr]--;
        }
    }
    for(int i=0;i<m;i++)mp[words[i]]++;
    return true;
}
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(),m = words.size(),wordSize = words[0].size(),si=0,ei=0,k=m*wordSize;
        vector<int> ans;
        unordered_map<string,int> mp;
        for(int i=0;i<m;i++)mp[words[i]]++;
        string str = "";
        while(ei<n){
            str.push_back(s[ei]);
            if((ei-si+1)<k)ei++;
            else{
                if(isSafe(mp,str,wordSize,words,m))ans.push_back(si);
                str = str.substr(1);
                si++;ei++;
            }
        }
        return ans;
    }
};
