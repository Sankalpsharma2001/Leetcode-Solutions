class Solution {
public:
    bool check(string str,string pat)
    {
        int i=0;
        for(int j=0;j<str.size();j++)
        {
            if(pat[i]==str[j])
            {
                i++;
                continue;
            }
            else if(str[j]>='A' and str[j]<='Z')
                return false;
        }
        return i==pat.size();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(string &x:queries)
        {
            if(check(x,pattern))
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};