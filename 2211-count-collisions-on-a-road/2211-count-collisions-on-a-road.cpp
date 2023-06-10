class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        int i=0;
        while(i<n && directions[i]=='L') i++;
        int r=0;
        int ans=0;
        for(;i<n;i++)
        {
            if(directions[i]=='R') r++;
            else if(directions[i]=='S')
            {
                ans+=r;
                r=0;
            }
            else
            {
                ans+=r+1;
                r=0;
            }
            
        }
        return ans;
    }
};