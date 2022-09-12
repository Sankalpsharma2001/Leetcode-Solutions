class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         vector<int> ans(1000+2,0);
        for(int i=0;i<trips.size();i++)
        {
            if(trips[i][0]>capacity)
                return false;
            ans[trips[i][1]]+=trips[i][0];
            ans[trips[i][2]]-=trips[i][0];
        }
        for(int i=1;i<=1001;i++)
        {ans[i]+=ans[i-1];
        }

        for(int i=1;i<=1001;i++)
           {
            if(ans[i]>capacity)
                return false;
            }
        return true;
    }
};