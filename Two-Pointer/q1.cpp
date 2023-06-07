class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(),si=0,ei=0,maxi=-1;
        vector<int> freq(26,0);
        vector<int> ans;
        for(int i=0;i<n;i++)freq[s[i]-'a']=i;
        while(ei<n){
            maxi = max(maxi,freq[s[ei]-'a']);
            if(ei==maxi){
                ans.push_back(maxi-si+1);
                si = ei+1;
            }
            ei++;
        }
        return ans;
    }
};
