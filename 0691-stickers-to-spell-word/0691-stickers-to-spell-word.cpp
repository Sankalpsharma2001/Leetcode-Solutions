class Solution {
public:
    int dp[32768]; // (2^15) length of target
    int solve(int mask,int allMask,vector<vector<int>> &arr,string target)
    {
        if(mask==allMask)
            return 0;
         if(dp[mask])
             return dp[mask];
        int x=51;
        for(vector<int> word:arr)
        {
            int newMask=mask;
            for(int i=0;i<target.size();i++)
            {
                if((mask&(1<<i))==0 && word[target[i]-'a'])
                {
                    newMask=newMask|(1<<i);
                    word[target[i]-'a']--;
                }
            }
            if(newMask!=mask)
            {
                x=min(x,1+solve(newMask,allMask,arr,target));
            }
        }
        return dp[mask]=x;
    }
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> arr(stickers.size());
        memset(dp,0,sizeof(dp));
        for(int i=0;i<stickers.size();i++)
        {
            vector<int> c(26,0);
            for(char &ch:stickers[i])
            {
                c[ch-'a']++;
            }
            arr[i]=c;
        }
        int allMask=(1<<target.size())-1;
        int val=solve(0,allMask,arr,target);
        return val<51?val:-1;
    }
};