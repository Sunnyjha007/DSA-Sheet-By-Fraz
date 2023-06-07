class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(),si=0,ei=0,ans=0,maxi=0;
        vector<int> freq(26,0);
        while(ei<n){
            freq[s[ei]-'A']++;
            maxi = max(maxi,freq[s[ei]-'A']);
            if((ei-si+1)-maxi>k){
                freq[s[si]-'A']--;
                si++;
            }
            ans = max(ans,(ei-si+1));
            ei++;
        }
        return ans;
    }
};
