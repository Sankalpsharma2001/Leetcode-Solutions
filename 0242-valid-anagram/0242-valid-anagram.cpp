class Solution {
public:
    bool isAnagram(string s, string t) {
      vector<int> m1(26,0),m2(26,0);
        for(char x='a';x<='z';x++)
            m1[x-'a']=0,m2[x-'a']=0;
        for(auto &x:s)
            m1[x-'a']++;
        for(auto &x:t)
            m2[x-'a']++;
    return m1==m2;
    }
};