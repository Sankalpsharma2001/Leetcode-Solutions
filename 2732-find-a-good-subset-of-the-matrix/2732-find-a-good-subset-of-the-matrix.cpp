class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
         
        vector<int> ans;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int ct=0;
                for(int k=0 ; k<m ; k++){
                    if((grid[i][k]&grid[j][k]) == 0) ct++;
                }
                
                if(ct == m) {
                   ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        
        for(int i=0 ; i<n ; i++){
            int ct=0;
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 0) ct++;
            }
            
            if(ct == m) return {i};
        }
        return {};
    }
};