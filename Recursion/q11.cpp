vector<string> freq = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
private:
void solve(string digits,vector<string>& ans,string v){
    if(digits.size()==0){
        ans.push_back(v);
        return;
    }
    string s = freq[digits[0]-'0'];
    digits = digits.substr(1);
    for(int i=0;i<s.size();i++){
        solve(digits,ans,v + s[i]);
    }   
}
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string> ans;
        string v;
        solve(digits,ans,v);
        return ans;
    }
};
vector<string> freq = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
private:
void solve(string digits,vector<string>& ans,string v,int idx){
    if(idx==digits.size()){
        ans.push_back(v);
        return;
    }
    string s = freq[digits[idx]-'0'];
    for(int i=0;i<s.size();i++){
        // v.push_back(s[i]);
        solve(digits,ans, v+s[i],idx+1);
        // v.pop_back();
    }
}
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string> ans;
        string v;
        solve(digits,ans,v,0);
        return ans;
    }
};
