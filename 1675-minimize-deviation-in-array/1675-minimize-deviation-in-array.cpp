class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> pq;
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2)
                nums[i]*=2;
            pq.push(nums[i]);
            mn=min(mn,nums[i]);
        }
        int ans=pq.top()-mn;
        while(pq.top()%2==0)
        {
            int x=pq.top();
            pq.pop();
            x/=2;
            pq.push(x);
            mn=min(mn,x);
            ans=min(ans,pq.top()-mn);
        }
        ans=min(ans,pq.top()-mn);
        return ans;
    }
    
};