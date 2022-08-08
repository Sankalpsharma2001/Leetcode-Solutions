class Solution {
public:
    vector<string> ans;
    void printAll(string s,int n,int open,int close)
    {
        if(open+close==2*n)
        {
            ans.push_back(s);
        }
        if(open<n)
        {
            printAll(s+'(',n,open+1,close);
        }
        if(close<open)
        printAll(s+')',n,open,close+1);
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        printAll(s,n,0,0);
        return ans;
    }
};