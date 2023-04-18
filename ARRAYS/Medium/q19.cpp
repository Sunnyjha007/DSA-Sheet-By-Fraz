#define mod 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int m = hc.size(),n = vc.size();
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int ans1 = max(hc[0],h-hc[m-1]);
        int ans2 = max(vc[0],w-vc[n-1]);
        for(int i=0;i<m-1;i++){
            ans1 = max(ans1,hc[i+1] - hc[i]);
            }
        for(int i=0;i<n-1;i++){
            ans2 = max(ans2,vc[i+1] - vc[i]);
        }
        cout<<ans1*w<<" "<<ans2<<" ";
          return (1l*ans1*ans2)%mod;
    }
};
