class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        bool mx=false,mn=false;
        long long mxStart=-1,mnStart=-1,start=0,ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            if(num<minK || num>maxK)
            {
                mx=false;
                mn=false;
                start=i+1;
            }
            if(num==minK)
            {
                mn=true;
                mnStart=i;
            }
            if(num==maxK)
            {
                mx=true;
                mxStart=i;
            }
            if(mx && mn)
            {
                ans+=(min(mxStart,mnStart)-start+1);
            }
        }
      
    return ans;
    }
};