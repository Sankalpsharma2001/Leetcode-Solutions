class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        for(int i=0;i<31;i++)
        {
            int x=start&(1<<i);
            int y=goal&(1<<i);
            if(x!=y) ans++;
        }
        return ans;
    }
};