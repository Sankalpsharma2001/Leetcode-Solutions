class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
          int m = mat.size(), n = mat[0].size();
        
        using ll = long long;
        vector<ll> rowMax(m, 0);
        vector<ll> colMax(n, 0);
        
        map<int,vector<pair<int,int>>> cells;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cells[mat[i][j]].push_back({i,j});
            }
        }
        
        ll result = 0;
        
        for(auto& it : cells) {
            vector<pair<int,int>>& arr = it.second;
            vector<ll> val(arr.size());
            
            for(int i=0; i<arr.size(); i++) {
                auto [x, y] = arr[i];
                val[i] = max(rowMax[x], colMax[y]) + 1;
                result = max(result, val[i]);
            }
            
            for(int i=0; i<arr.size(); i++) {
                auto [x, y] = arr[i];
                rowMax[x] = max(rowMax[x], val[i]);
                colMax[y] = max(colMax[y], val[i]);
            }
        }
        
        return result;
    }
};