class Solution {
public:
    vector<int> count(string &s)
    {
        vector<int> v(26,0);
        for(char &c:s)
        {
            v[c-'a']++;
        }
        return v;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
       vector<int> maxFre(26,0);
        vector<string> ans;
        for(auto x:words2)
        {
            vector<int> fre=count(x);
            int i;
            for(i=0;i<26;i++)
            {
                maxFre[i]=max(maxFre[i],fre[i]);
            }
        }
        for(auto &x:words1)
        {
            vector<int> fre=count(x);
            int i;
            for( i=0;i<26;i++)
            {
                if(fre[i]<maxFre[i]) break;
            }
            if(i==26)
                ans.push_back(x);
        }
        return ans;
    }
};