class Solution {
public:
   int minIncrements(int n, vector<int>& cost) {
        int ans=0;
        for(int i=n/2-1;i>=0;i--){
            int x=2*i+1,y=2*i+2;
            int minm=min(cost[x],cost[y]),maxm=max(cost[x],cost[y]);
            ans+=abs(maxm-minm);
            cost[i]+=maxm;
        }
        return ans;
    }
};