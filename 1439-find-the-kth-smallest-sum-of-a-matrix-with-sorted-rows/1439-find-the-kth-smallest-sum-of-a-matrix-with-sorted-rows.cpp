#define pi pair<int,vector<int>>
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> temp=mat[0];
      
        
        for(int i=1;i<n;i++)
        {
            vector<int> v;
            for(int j=0;j<m;j++)
            {
                for(int l=0;l<temp.size();l++)
                {
                    v.push_back(temp[l]+mat[i][j]);
                }
            }
            sort(v.begin(),v.end());
            temp.clear();
            for(int j=0;j<min(k,(int)v.size());j++)
            {
                temp.push_back(v[j]);
            }
            
        }
        
        return temp[k-1];
    }
};