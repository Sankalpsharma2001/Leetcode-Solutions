class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
       map<int,pair<int,int>> mp;
        map<int,int> m1,m2;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                mp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            auto x=mp[arr[i]];
            m1[x.first]++;
            m2[x.second]++;
            if(m1[x.first]==mat[0].size() || m2[x.second]==mat.size())
            {
                return i;
            }
        }
        return -1;
    }
        
    
};