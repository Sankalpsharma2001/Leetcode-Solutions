class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s!="1")
        {
            if(s.back()=='0') s.pop_back();
            else
            {
                while(!s.empty() && s.back()=='1')
                {
                    s.pop_back();
                    ans++;
                }
                if(s.empty()) return ans+1;
                else s.back()='1';
            }
            ans++;
        }
        return ans;
    }
};