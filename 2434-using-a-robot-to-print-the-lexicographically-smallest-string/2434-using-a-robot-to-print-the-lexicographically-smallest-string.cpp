class Solution {
public:
    char character(vector<int> &freq)
    {
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                return i+'a';
            }
        }
        return 'z';
    }
    string robotWithString(string s) {
        string ans="",t="";
        vector<int> freq(26,0);
        for(auto &c:s)
        {
            freq[c-'a']++;
        }
        
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
           t+=c;
            freq[c-'a']--;
            while(t.size() && t.back()<=character(freq))
            {
                ans+=t.back();
                t.pop_back();
                
            }
        }
        return ans;
    }
};