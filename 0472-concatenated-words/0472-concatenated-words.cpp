class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s;
        for(string &it:words) {
            s.insert(it);
        }
        vector<string> ans;
        for(auto &w:words)
        {
            int n=w.size();
            vector<int> dp(n+1,0);
            dp[0]=1;
            for(int i=0;i<n;i++)
            {
                if (!dp[i]) continue;
                for(int j=i+1;j<=n;j++)
                {
                    if(j-i<n && s.count(w.substr(i,j-i)))
                    {
                        dp[j]=1;
                    }
                }
            }
            if(dp[n])
            {
                ans.push_back(w);
            }
        }
        return ans;
        
    }
};