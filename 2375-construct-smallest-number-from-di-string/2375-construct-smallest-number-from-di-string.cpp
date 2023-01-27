class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        string ans="";
        int j=0;
        for(int i=0;i<=pattern.size();i++)
        {
          ans+=('1'+i);
            if(i==pattern.size() || pattern[i]=='I')
            {
                reverse(ans.begin()+j,ans.end());
                j=i+1;
            }
        }
        return ans;
    }
};