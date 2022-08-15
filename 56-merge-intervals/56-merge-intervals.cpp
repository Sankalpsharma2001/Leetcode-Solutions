class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        ans.push_back(v[0]);
        for(int i=1;i<v.size();i++)
        {
            if(ans.back()[1]>=v[i][0])
            {
                ans.back()[0]=min(ans.back()[0],v[i][0]);
                ans.back()[1]=max(ans.back()[1],v[i][1]);
            }
            else
            {
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};