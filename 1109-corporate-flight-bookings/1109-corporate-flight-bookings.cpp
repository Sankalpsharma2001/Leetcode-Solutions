class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+2,0);
        for(int i=0;i<bookings.size();i++)
        {
            ans[bookings[i][0]]+=bookings[i][2];
            ans[bookings[i][1]+1]-=bookings[i][2];
        }
        vector<int> res(n,0);
        for(int i=0;i<n;++i){
            if(i==0)
                res[i] = ans[i+1];
            else
                res[i] = res[i-1] + ans[i+1];
        }
      
        return res;
    }
};