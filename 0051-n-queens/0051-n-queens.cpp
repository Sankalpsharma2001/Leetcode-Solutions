class Solution {
public:
  vector<vector<string>> res;
    bool safe(int row,int col, vector<string> &ans,int n)
    {
    
	for(int i = 0; i <= row; i++) {
		if(ans[i][col]=='Q') return false; // checking if any queen already placed on same column previously
		// checking if all diagonals are safe -
		if(row - i >= 0 && col - i >= 0 && ans[row - i][col - i]=='Q') return false;
		if(row - i >= 0 && col + i <  n && ans[row - i][col + i]=='Q') return false;
	}
	return true;
    }
    bool solve( vector<string> &ans,int row,int n)
    {
        if(row>=n) {
            res.push_back(ans);
            return true;
        }
        for(int col=0;col<n;col++)
        {
            if(safe(row,col,ans,n))
            {
                ans[row][col]='Q';
                solve(ans,row+1,n);
                ans[row][col]='.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ans(n, string(n, '.'));
        bool f=solve(ans,0,n);
        return res;
    }
};