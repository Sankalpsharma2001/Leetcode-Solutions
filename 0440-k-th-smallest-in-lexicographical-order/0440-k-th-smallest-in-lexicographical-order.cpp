class Solution {
public:
    int calSteps(long n,long n1,long n2)
    {
        int step=0;
        while(n1<=n)
        {
            step+=min(n+1,n2)-n1;
            n1*=10;
            n2*=10;
        }
        return step;
    }
    
    int findKthNumber(int n, int k) {
        long cur=1;
        k--;
        while(k>0)
        {
            int step=calSteps(n,cur,cur+1);
            if(step<=k)
            {
                k-=step;
                cur+=1;
            }
            else
            {
                cur*=10;
                 k--;
            }
            
        }
        return cur;
    }
};