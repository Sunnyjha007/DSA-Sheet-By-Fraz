class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(),k = p.size(),si=0,ei=0;
        vector<int> ans;
        vector<int> window(26,0),check(26,0);
        for(int i=0;i<p.size();i++)window[p[i]-'a']++;
        while(ei<n){
            check[s[ei]-'a']++;
            if((ei-si+1)<k)ei++;
            else{
                if(window==check){
                    ans.push_back(si);
                }
                check[s[si]-'a']--;
                si++;ei++;
            }
        }
        return ans;
    }
};
