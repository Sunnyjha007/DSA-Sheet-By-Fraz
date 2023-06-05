class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(),si=0,ei=0,ans=0;
        if(n==0)return 0;
        set<char> st;
        while(ei<n){
            if(!st.count(s[ei])){
                st.insert(s[ei]);
                ans = max(ans,ei-si+1);
                 ei++;
            }else{
                st.erase(s[si]);
                si++;
            }
        }
        return ans;
    }
};
