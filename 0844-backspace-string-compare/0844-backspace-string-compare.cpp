class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a="",b="";
        for(auto &ch:s)
        {
            if(ch=='#') {if(a.size()>0)a.pop_back();}
            else a.push_back(ch);
        }
        
        for(auto &ch:t)
        {
            if(ch=='#') {if(b.size()>0)b.pop_back();}
            else b.push_back(ch);
        }
        return a==b;
    }
};