
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if(n==0||n<k)return 0;
        if(k==1)return n;
        unordered_map<char,int> mp;
        for(auto it:s)mp[it]++;
        int cnt=0;
        while(cnt<n&&mp[s[cnt]]>=k)cnt++;
        if(cnt==n)return n;
        int ans1 =longestSubstring(s.substr(0,cnt),k);
        while(cnt < n && mp[s[cnt]] < k) cnt++;
        int ans2 = cnt<n? longestSubstring(s.substr(cnt),k):0;
        return max(ans1,ans2); 
    }
};
