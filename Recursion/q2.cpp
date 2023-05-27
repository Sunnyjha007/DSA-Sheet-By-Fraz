class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(),si=0,ei=n-1;
        while(si<=ei){
            if(!isalnum(s[si]))si++;
            else if(!isalnum(s[ei]))ei--;
            else if(tolower(s[si])!=tolower(s[ei]))return false;
            else {si++;ei--;}
        }
        return true;
    }
};
