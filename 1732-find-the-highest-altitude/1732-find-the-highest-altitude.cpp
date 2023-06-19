class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,h=0;
        for(int i=0;i<gain.size();i++)
        {
            h+=gain[i];
            ans=max(ans,h);
        }
        return ans;
    }
};