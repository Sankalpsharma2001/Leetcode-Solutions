class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> s;
        for(auto &it:ideas)
        {
            s.insert(it);
        }
        
        vector<vector<long long>> dp(26,vector<long long>(26,0));
        for(int i=0;i<ideas.size();i++)
        {
            string str=ideas[i].substr(1);
            int c=ideas[i][0]-'a';
            for(int j=0;j<26;j++)
            {
                char ch=j+'a';
                string t=ch+str;
                if(s.find(t)==s.end())
                {
                    dp[c][j]++;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(i!=j)
                    ans+=(dp[i][j]*dp[j][i]);
            }
        }
        return ans;
    }
};