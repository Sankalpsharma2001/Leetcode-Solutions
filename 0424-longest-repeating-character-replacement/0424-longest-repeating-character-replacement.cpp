class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        unordered_map<char,int> m;
        int mxfre=0,ans=0;
        for(int j=0;j<s.size();j++)
        {
         m[s[j]]++;
            mxfre=max(mxfre,m[s[j]]);
            if(j-i+1-mxfre>k)
            {
                m[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};