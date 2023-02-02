class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
      unordered_map<char,int> m;
        int i=0;
        for(char c:order)
        {
            m[c]=i++;
        }
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                int mn=min(words[i].size(),words[j].size());
                for(int k=0;k<mn;k++)
                {
                    if(m[words[i][k]]<m[words[j][k]])
                    {
                        break;
                        
                    }
                    else if(m[words[i][k]]==m[words[j][k]])
                    {
                        if(k==mn-1)
                        {
                            if(words[j].size()<words[i].size()) return false;
                        }
                        
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};