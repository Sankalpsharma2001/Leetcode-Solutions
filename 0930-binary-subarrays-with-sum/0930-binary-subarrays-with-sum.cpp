class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        map<int,int> m;
        m[0]=1;
        int ans=0,s=0;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            if(m.find(s-goal)!=m.end())
            {
                ans+=m[s-goal];
            }
            m[s]++;
        }
        return ans;
    }
};