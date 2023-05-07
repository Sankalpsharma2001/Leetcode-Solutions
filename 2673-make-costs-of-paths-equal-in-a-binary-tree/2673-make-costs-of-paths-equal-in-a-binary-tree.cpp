class Solution {
public:
     int res = 0;
    
    int dfs(int i,vector<int> &cost)
    {
      if (i >= cost.size()) return 0;
        int a = dfs(2 * i + 1,cost), b = dfs(2 * i + 2,cost);
        res += abs(a - b);
        return cost[i] + max(a, b);   
    }
    int minIncrements(int n, vector<int>& cost) {
       
    dfs(0,cost);
    return res;
    }
};