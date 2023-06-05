class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(),si=0,ei=0,sum=0,ans=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)sum+=customers[i];
        }
        while(ei<n){
            if(grumpy[ei])sum+=customers[ei];
            if((ei-si+1)<minutes)ei++;
            else{
                ans = max(ans,sum);
                if(grumpy[si])sum-=customers[si];
                si++;ei++;
            }
        }
        return ans;
    }
};
