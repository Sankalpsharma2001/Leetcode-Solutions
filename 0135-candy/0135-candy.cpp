class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> can(n+1,0);
        can[0]=1;
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                can[i]=1+can[i-1];
            else
                can[i]=1;
                
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                can[i]=max(can[i],1+can[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=can[i];
        return ans;
    }
};