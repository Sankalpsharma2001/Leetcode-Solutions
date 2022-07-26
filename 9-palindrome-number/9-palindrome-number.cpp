class Solution {
public:
    bool isPalindrome(int x) {
    ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string s=to_string(x);
        int n=s.size();
        int i=0,j=n-1;
        if(s[0]=='-')
            return false;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};