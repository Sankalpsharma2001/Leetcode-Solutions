class Solution {
public:
   static bool com(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(intervals.begin(),intervals.end(),com);
        vector<int> pre=intervals[0];
        int ans=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(pre[1]>intervals[i][0])
            {
                ans++;
            }
            else
                pre=intervals[i];
        }
        return ans;
    }
};