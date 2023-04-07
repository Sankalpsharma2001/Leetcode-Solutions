class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
       
        int m=rolls.size();
        int s=accumulate(rolls.begin(),rolls.end(),0);
        int sum=(n+m)*mean;
        int rem=sum-s;
        if(rem>n*6 || rem<n)
        {
            return {};
        }
        if(rem==0 && n==0)
        {
            return rolls;
        }
        vector<int> ans(n,rem/n);
        int r=rem%n;
        for(int i=0;i<r;i++)
            ans[i]++;
        
        return ans;
    }
};