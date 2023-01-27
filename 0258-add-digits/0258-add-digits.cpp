class Solution {
public:
    int addDigits(int num) {
        int ans=num;
        while(ans/10>0)
        {
            string s=to_string(ans);
            ans=0;
            for(int i=0;i<s.size();i++)
            {
                ans+=(s[i]-'0');
            }
        }
        return ans;
    }
};