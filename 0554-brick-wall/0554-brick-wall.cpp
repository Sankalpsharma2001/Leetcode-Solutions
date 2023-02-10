class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
      
           unordered_map<int,int> m;
        int mxFre=0;
        for(int i=0;i<wall.size();i++)
        {
            int edge=0;
            for(int j=0;j<wall[i].size()-1;j++)
            {
                edge+=wall[i][j];
                m[edge]++;
                mxFre=max(mxFre,m[edge]);
            }
        }
        return wall.size()-mxFre;
    }
};