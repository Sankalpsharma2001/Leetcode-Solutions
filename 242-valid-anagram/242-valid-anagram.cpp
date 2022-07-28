class Solution {
public:
    bool isAnagram(string s, string t) {
      unordered_map<char,int> m1,m2;
        for(char x='a';x<='z';x++)
            m1[x]=0,m2[x]=0;
        for(auto &x:s)
            m1[x]++;
        for(auto &x:t)
            m2[x]++;
    return m1==m2;
    }
};