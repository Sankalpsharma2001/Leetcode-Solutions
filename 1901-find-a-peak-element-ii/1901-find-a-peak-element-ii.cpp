class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int n = mat.size(), m = mat[0].size();
        int lo = 0, hi = n - 1, mid;
        int max_c = 0;
         while(lo <= hi) {
            mid = (lo + hi) / 2;
            for(int i = 0; i < m; ++i) {
                if(mat[mid][max_c] < mat[mid][i]) max_c = i;
            }

            bool upSmall = mid <= 0 || mat[mid - 1][max_c] < mat[mid][max_c];
            bool downSmall = mid >= n - 1 || mat[mid + 1][max_c] < mat[mid][max_c];
            if(upSmall && downSmall || lo == hi) {
                return { mid, max_c };
            }

            if(downSmall) hi = mid - 1;
            else lo = mid + 1;
        }
        return { -1, -1 };
    }
};