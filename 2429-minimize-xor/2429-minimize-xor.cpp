class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0;
        while(num2>0)
        {
            cnt+=num2&1;
            num2/=2;
        }
        vector<int> vis(32,0);
        int ans=0;
        for(int i=31;i>=0 && cnt>0;i--)
        {
            if((num1>>i)&1)
            {
                ans|=(1<<i);
                vis[i]=1;
                cnt--;
            }
        }
        if(cnt==0) return ans;
        for(int i=0;i<32 && cnt>0;i++)
        {
            if(vis[i]==0)
            {
                ans|=(1<<i);
                cnt--;
            }
        }
        return ans;
        
    }
};