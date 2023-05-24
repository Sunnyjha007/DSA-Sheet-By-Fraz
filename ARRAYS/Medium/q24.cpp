class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> name,city;
        vector<int> time,amount;
        int n = transactions.size(),cnt=0,i=0;
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[transactions[i]]++;
        }
        while(i<n){
            string st = transactions[i];
            int m = st.size(),j=0,cnt=0;
            while(j<m){
                int k = j;
                while(st[k]!=','&&k<=m-1){
                    k++;
                    // cout<<k<<" ";
                }
                string s = st.substr(j,k-j);
                // cout<<s<<" ";
                j = k+1;
                cnt++;
                if(cnt==1){
                    name.push_back(s);
                }else if(cnt==2){
                    time.push_back(stoi(s));
                }else if(cnt==3){
                    amount.push_back(stoi(s));
                }else{
                    city.push_back(s);
                }
            }
            i++;
        }
        set<string> tempans;
        vector<string> ans;
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j){
                        if(abs(time[j]-time[i])<=60&&name[j]==name[i]&&city[j]!=city[i]||amount[i]>1000){
                        tempans.insert(transactions[i]);
                        break;
                    }
                }
            }
        }
        while(!tempans.empty()){
            string s = *(tempans.begin());
            int cnt = mp[s];
            for(int i=0;i<cnt;i++){
                ans.push_back(*(tempans.begin()));
            } 
            tempans.erase(tempans.begin());
        }
        return ans;
    }
};
