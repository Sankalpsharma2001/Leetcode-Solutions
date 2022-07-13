class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
           if(mat.empty()) return {};
        
         int N = mat.size();
         int M = mat[0].size();
        
        vector<int> res;
        for(int s = 0; s <= N + M - 2; ++s)
        {
            // for all i + j = s
            for(int x = 0; x <= s; ++x) 
            {
                int i = x;
                int j = s - i;
                if(s % 2 == 0) swap(i, j);

                if(i >= N || j >= M) continue;
                
                res.push_back(mat[i][j]);
            }
        }
        
        return res;
    }
};