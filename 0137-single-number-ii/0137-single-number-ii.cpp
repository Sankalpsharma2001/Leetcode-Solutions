class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> bit(32,0);
       int ans=0;
            for(int j=0;j<32;j++)
            {
                int cnt=0;
                for(int i=0;i<n;i++)
                {
                    if(((nums[i]>>j) &1))
                       cnt++;
                }
                if((cnt%3)==1)
                    ans+=(1<<j);
            }
        return ans;
        
    }
};