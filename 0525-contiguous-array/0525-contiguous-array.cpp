class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int z=0;
        map<int,int> m;
        int ans=0;
        m[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1) z++;
            else z--;
            if(m.find(z)==m.end())
            {
                m[z]=i;
            }
            else
            {
                ans=max(ans,i-m[z]);
            }
        }
        return ans;
    }
};