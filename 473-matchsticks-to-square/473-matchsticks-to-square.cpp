class Solution {
public:
    bool solve(vector<int>& m,vector<int> &s,int len,int idx)
    {
        if(idx==m.size())
            return true;
        for(int i=0;i<4;i++)
        {
            if(s[i]+m[idx]<=len)
            {
                s[i]+=m[idx];
                if(solve(m,s,len,idx+1))
                    return true;
                s[i]-=m[idx];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
       int per=0;
        for(auto &x:matchsticks)
        {
            per+=x;
        }
        if(per%4)
            return false;
        int len=per/4;
        vector<int> sides(4,0);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return solve(matchsticks,sides,len,0);
    }
};