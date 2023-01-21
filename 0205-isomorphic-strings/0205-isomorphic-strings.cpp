class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        map<char,char> m;
        set<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])==m.end())
            {
                m[s[i]]=t[i];
                if(st.find(t[i])!=st.end())
                {
                    return false;
                }
                st.insert(t[i]);   
            }
            else
            {
                if(m[s[i]]!=t[i] )
                {
                    return false;
                }
            }
        }
        return true;
    }
};