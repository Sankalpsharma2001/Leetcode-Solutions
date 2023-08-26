class Solution {
public:
  static bool cmp(vector<int> &a,vector<int>&b)
    {
            return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), cmp);
        //sort by end
       int ans=1,x=pairs[0][1];
        for(int i=1;i<pairs.size();i++)
        {
            if(x<pairs[i][0])
            {
                x=pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};