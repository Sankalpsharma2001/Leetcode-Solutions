class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        unordered_map<int,int> m;
        for(auto x:s)
            m[x]++;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]==1)
                return i;
        }
        return -1;
    }
};