class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int,int> mp;
        long long  ans = 0;
        for(int i=0;i<n;i++)mp[time[i]%60]++;
        for(auto it:mp){
            if(it.first==0||it.first==30){
                int a = it.second;
                int b = (it.second-1);
                if(a%2==0)a = a/2;
                else b = b/2;
                ans+= a*b;
                it.second = 0;
            }else{
                if(mp.count(60-it.first)){
                    ans+= it.second*(mp[60-it.first]);
                    it.second = 0;
                    mp[60-it.first] = 0;
                }
            }
        }
        return ans;
    }
};
/*
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i=0;i<n;i++){
           int val = time[i]%60;
           if(val==0){
               ans+= mp[val];
           }else{
               ans+= mp[60-val];
           }
           mp[val]++;
        }
        return ans;
    }
};
*/
