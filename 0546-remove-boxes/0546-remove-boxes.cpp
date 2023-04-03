class Solution {
public:
    int dp[100+1][100+1][100+1];
    int solve(int left,int right,int streak,vector<int> &boxes)
    {
        if(left>right) return 0;
        if(left==right)
        {
            return (streak+1)*(streak+1);
        }
        if(dp[left][right][streak]!=-1)
            return dp[left][right][streak];
        int ans=(streak+1)*(streak+1)+solve(left+1,right,0,boxes);
        for(int i=left+1;i<=right;i++)
        {
            if(boxes[i]==boxes[left])
            {
                ans=max(ans,solve(left+1,i-1,0,boxes)+solve(i,right,streak+1,boxes));
            }
        }
        return dp[left][right][streak]=ans;
    }
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,0,boxes);
    }
};