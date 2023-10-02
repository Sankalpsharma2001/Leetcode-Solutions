class Solution {
public:
    vector<vector<string>> ans;
    bool ispalindrome(string s,int i,int j)
    {
        while(i<j)
        {  if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string s,int i,int j,vector<string> &v)
    {
        if(i>j)
        {
            ans.push_back(v);
            return;
        }
        for(int st=i;st<=j;st++)
        {
            if(ispalindrome(s,i,st))
            {
                v.push_back(s.substr(i,st-i+1));
                solve(s,st+1,j,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ans.clear();
        vector<string> v;
        solve(s,0,s.size()-1,v);
        return ans;
    }
};