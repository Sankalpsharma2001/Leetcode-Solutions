class Solution {
public:
     bool isValid(int n, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n) return false;
        return true;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
         int n = grid.size();
        int currRow = 0, currCol = 0;
        
        int currStepIdx = 0;
        vector<int>rows = {-2, -2, +2, +2, -1, +1, -1, +1};
        vector<int>cols = {-1, +1, -1, +1, -2, -2, +2, +2};
        while(currStepIdx < ((n * n) - 1))
        {
            bool found = false;
            for (int dirIdx = 0; dirIdx < 8; dirIdx++)
            {
                int newRow = currRow + rows[dirIdx];
                int newCol = currCol + cols[dirIdx];

                if (isValid(n, newRow, newCol) && grid[newRow][newCol] == currStepIdx + 1) 
                {
                    currStepIdx++;
                    currRow = newRow;
                    currCol = newCol;
                    found = true; break;
                }
            }
            if (!found) return false;
        }
        return true;  

    }
};