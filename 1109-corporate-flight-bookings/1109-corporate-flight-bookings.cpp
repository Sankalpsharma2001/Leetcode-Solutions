class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+2,0);
        for(int i=0;i<bookings.size();i++)
        {
            ans[bookings[i][0]]+=bookings[i][2];
            ans[bookings[i][1]+1]-=bookings[i][2];
        }
        for(int i=1;i<=n;i++)
            ans[i]+=ans[i-1];
        vector<int> res;
        for(int i=1;i<=n;i++)
            res.push_back(ans[i]);
        return res;
    }
};