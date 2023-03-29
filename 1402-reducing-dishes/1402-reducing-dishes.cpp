class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int c=1,res=0;
            for(int j=i;j<n;j++)
            {
                res+=(satisfaction[j]*c);
                c++;
            }
            ans=max(ans,res);
        }
        return ans;
        
    }
};