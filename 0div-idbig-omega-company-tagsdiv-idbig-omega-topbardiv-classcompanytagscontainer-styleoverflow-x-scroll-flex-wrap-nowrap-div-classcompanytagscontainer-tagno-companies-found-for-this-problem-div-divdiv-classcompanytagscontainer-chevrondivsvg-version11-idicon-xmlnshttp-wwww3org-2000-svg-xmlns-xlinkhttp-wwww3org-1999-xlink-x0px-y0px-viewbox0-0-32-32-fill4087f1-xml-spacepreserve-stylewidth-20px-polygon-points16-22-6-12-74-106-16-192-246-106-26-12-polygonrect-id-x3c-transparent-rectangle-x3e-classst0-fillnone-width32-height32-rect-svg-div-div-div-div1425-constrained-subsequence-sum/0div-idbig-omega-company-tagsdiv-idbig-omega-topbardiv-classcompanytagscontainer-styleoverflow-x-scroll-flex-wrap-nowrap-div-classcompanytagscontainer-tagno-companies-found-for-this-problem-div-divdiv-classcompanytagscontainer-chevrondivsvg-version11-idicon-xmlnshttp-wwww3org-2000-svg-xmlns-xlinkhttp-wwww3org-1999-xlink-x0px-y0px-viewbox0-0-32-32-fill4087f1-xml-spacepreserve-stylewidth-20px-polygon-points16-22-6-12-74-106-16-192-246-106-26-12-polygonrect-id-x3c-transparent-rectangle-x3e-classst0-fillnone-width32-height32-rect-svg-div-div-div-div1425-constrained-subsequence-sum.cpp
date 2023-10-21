class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
       int n=nums.size();
        int ans=nums[0];
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        for(int i=1;i<n;i++)
        {
            while(i-pq.top().second>k)
            {
                pq.pop();
            }
            int x=max(0,pq.top().first)+nums[i];
            ans=max(ans,x);
            pq.push({x,i});
        }
        return ans;
        
    }
};