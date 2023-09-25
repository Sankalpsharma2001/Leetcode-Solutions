class Solution {
public:
    char findTheDifference(string s, string t) {
       
        int xor_=0;
        for(int i=0;i<s.size() or i<t.size();i++)
        {
            if(i<s.size())
            {
             xor_^=(s[i]-'a');
            }
            if(i<t.size())
            {
                xor_^=(t[i]-'a');
            }
        }
        return xor_+'a';
    }
};