class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
         vector<vector<int>> ans(2, vector<int>(colsum.size()));
         for(int i=0;i<colsum.size();i++)
         {
             if(colsum[i]==2)
             {
                 lower--;
                 upper--;
                 ans[0][i]=1;
                 ans[1][i]=1;
             }
             else if(colsum[i]==1)
             {
                 if(upper>lower)
                 {
                     ans[0][i]=1;
                     upper--;
                 }
                 else
                 {
                     ans[1][i]=1;
                     lower--;
                 }
             }
             if(lower<0 || upper<0) return {};
         }
         if (upper!=0 || lower!=0) return {};
        return ans;
    }
};