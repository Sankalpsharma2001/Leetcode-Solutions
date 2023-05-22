class Solution {
public:
    void solve(string s,string v,vector<string> &ans,int idx)
    {
        if(idx==s.size())
        {
            ans.push_back(v);
            return;
        }
        if(s[idx]>='0' && s[idx]<='9')
        {
            v.push_back(s[idx]);
            solve(s,v,ans,idx+1);
        }
        else
        {
              char ch=s[idx];
              v.push_back(tolower(ch));
            solve(s,v,ans,idx+1);
            v.pop_back();
            v.push_back(toupper(ch));
            solve(s,v,ans,idx+1);
            
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        
        solve(s,"",ans,0);
        return ans;
    }
};