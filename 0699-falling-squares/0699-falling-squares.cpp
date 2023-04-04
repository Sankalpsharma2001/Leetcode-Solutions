class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        vector<vector<int>> v;
        int h=0;
        for(int i=0;i<positions.size();i++)
        {
            int left=positions[i][0],right=positions[i][0]+positions[i][1],mx=0;
            for(int j=0;j<v.size();j++)
            {
                if(v[j][1]>left && v[j][0]<right)
                {
                    mx=max(mx,v[j][2]);
                }
            }
            v.push_back({left,right,mx+positions[i][1]});
            h=max(h,v.back()[2]);
            ans.push_back(h);
        }
        return ans;
    }
};