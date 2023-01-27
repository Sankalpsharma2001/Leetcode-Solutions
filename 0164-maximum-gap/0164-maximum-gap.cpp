class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        int mn=INT_MAX,mx=INT_MIN;
        for(int n:nums)
        {
            mn=min(n,mn);
            mx=max(n,mx);
        }
        int interval=(int)ceil((double)(mx-mn)/(n-1));
        vector<int> bucketMin(n-1,INT_MAX);
        vector<int> bucketMax(n-1,-1);
        for(int i=0;i<n;i++)
        {
          if(nums[i]==mn || nums[i]==mx)  continue;  
            int index=(nums[i]-mn)/interval;
            bucketMin[index]=min(bucketMin[index],nums[i]);
            bucketMax[index]=max(bucketMax[index],nums[i]);
            
        }
        int prev=mn;
        int gap=0;
         for(int i=0;i<bucketMin.size();i++)
         {
             if(bucketMax[i]==-1) continue;
             gap=max(gap,bucketMin[i]-prev);
             prev=bucketMax[i];
         }
        gap=max(gap,mx-prev);
        return gap;
        
    }
};