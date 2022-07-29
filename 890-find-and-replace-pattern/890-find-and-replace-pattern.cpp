class Solution {
public:
    vector<int> foundPattern(string s)
    {
     vector<int> p;
        unordered_map<char,int> m;
        int ind=0;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])==m.end())
            {
                m.insert({s[i],ind++});
                p.push_back(m[s[i]]);
            }
            else
            {
                p.push_back(m[s[i]]);
            }
        }
        return p;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        unordered_map<char,int> m;
        vector<int> v=foundPattern(pattern);
        for(int i=0;i<words.size();i++)
        {
            vector<int> temp=foundPattern(words[i]);
            if(temp==v)
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};