#define ll long long
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
       int n=nums.size();
       vector<vector<ll>> greaterThan(n,vector<ll>(n,0)),lesserThan(n,vector<ll>(n,0));
       
       // let greaterThan[i][j] represent number of elements in range i to j which are greater than nums[i]
        
        // let lesserThan[i][j] represent number of elements in range i to j which are lesser than nums[j];
        for(int i=0;i<n;i++)
        {
            int t=0;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[i])
                {
                    t++;
                }
                greaterThan[i][j]=t;
            }
        }
        
        for(int j=0;j<n;j++)
        {
            int t=0;
            for(int i=j-1;i>=0;i--)
            {
                if(nums[j]>nums[i])
                {
                    t++;
                }
                lesserThan[i][j]=t;
            }
        }
        
        long long ans=0;
        for(int j=1;j<n-2;j++)
        {
            for(int k=j+1;k<n-1;k++)
            {
                if(nums[j]>nums[k])
                {
                    int pos_i=(lesserThan[0][k]-lesserThan[j][k]);
                    int pos_l=(greaterThan[j][n-1]-greaterThan[j][k]);
                    ans+=pos_i*pos_l*1ll;
                }
            }
        }
        return ans;
        
    }
};