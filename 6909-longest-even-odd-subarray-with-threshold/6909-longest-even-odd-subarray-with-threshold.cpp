class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
       int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            bool f=true;
            if(nums[i]%2 || nums[i]>threshold)continue;
            int c=1;
            for(int j=i;j<n-1;j++)
            {
                if(nums[j]%2!=nums[j+1]%2 && nums[j]<=threshold && nums[j+1]<=threshold)
                {
                   
                    c++;
                }
                
                else
                    break;
            }
            ans=max(ans,c);
            
        }
          return ans;
    }
  
};