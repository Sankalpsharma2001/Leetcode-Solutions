#define ll long long
class Solution {
public:
    bool isFive(int num) {
        while (num > 1) {
            if (num % 5 != 0) {
                return false;
            }
            num /= 5;
        }
        return num == 1;
    }
    bool check(int i, int j, string &s)
    {
        string str = s.substr(i, j + 1 - i);
        int k = 0;
        while (k < str.size())
        {
            if (str[k] == '0')
            {
                k++;
                return false;
            }
            else
                break;
        }
        int ans = 0;
        int x=0;
        for (int i = str.size() - 1; i >= 0; --i)
        {
            
                ans += (pow(2,x)*(str[i]-'0'));
            x++;
        }
        return (isFive(ans));
    }
    int dp[16][16];
    int solve(int i,int j,string &s)
    {
        if(i==j) return s[i]=='1'?0:1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        if(check(i,j,s)) return 0;
        for(int idx=i;idx<j;idx++)
        {
            
            int t=1+solve(i,idx,s)+solve(idx+1,j,s);
            ans=min(ans,t);
            
        }
        return dp[i][j]=ans;
    }
    int minimumBeautifulSubstrings(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,n,s);
        return ans==1e9?-1:ans+1;
    }
};