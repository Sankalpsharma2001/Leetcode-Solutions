class Solution {
public:
   
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
      
        int rows = matrix.size();
        int cols = matrix[0].size();
      
        int maxSum=-1e9;
        int leftBound=0;
        int rightBound=0;
        int upBound=0;
        int lowBound=0;
        for(int left = 0; left < cols ; left++){
           vector<int> sums(rows,0);
            for(int right = left; right < cols; right++){
                
                for(int i=0; i < rows; i++){
                    sums[i] += matrix[i][right];
                }
              set<int> accuSet;
            accuSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for (int sum : sums) {
                curSum += sum;
                set<int>::iterator it = accuSet.lower_bound(curSum - k);
                if (it != accuSet.end()) curMax = max(curMax, curSum - *it);
                accuSet.insert(curSum);
            }
            maxSum = max(maxSum, curMax);
                }
            }
        
        return maxSum;
    }
};