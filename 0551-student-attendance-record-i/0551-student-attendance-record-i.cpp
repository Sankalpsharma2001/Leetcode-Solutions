class Solution {
public:
    bool checkRecord(string s) {
        int n=s.size();
        int a=count(s.begin(),s.end(),'A');
        if(a>=2) return false;
        for(int i=0;i<n-2;i++)
        {
            if(s[i]==s[i+1] && s[i]==s[i+2] && s[i]=='L')
                return false;
        }
        return true;
    }
};