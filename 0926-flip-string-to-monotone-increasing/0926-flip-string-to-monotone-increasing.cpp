class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int z=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0') z++;
        }
        
        // left1+right0
        int ans=z;
        for(char ch:s)
        {
            if(ch=='0')
            {
                z--;
                ans=min(ans,z);
            }
            else
            {
                z++;
            }
        }
        return ans;
    }
};