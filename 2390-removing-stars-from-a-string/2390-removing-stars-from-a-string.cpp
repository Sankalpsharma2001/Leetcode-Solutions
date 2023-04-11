class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*')
               ans+=s[i];
            else
            {
                if(ans.size())
                ans.pop_back();
            }
        }
       
        return ans;
    }
};