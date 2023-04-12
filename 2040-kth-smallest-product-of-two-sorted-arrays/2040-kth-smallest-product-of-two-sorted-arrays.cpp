#define ll long long
class Solution {
public:
    bool check(ll mid,vector<int>& nums1,vector<int>& nums2,long long k)
    {
        ll c=0;
        for(int i=0;i<nums1.size();i++)
        {
            ll val=nums1[i];
//If val == 0, product of val and each element in nums2 will be 0. And if midval>=0, then because all products are 0, all products will be smaller or equal to mid. So we can add all products in the answer
            if(val==0 && mid>=0)
            {
                c+=nums2.size();
            }
            else if(val>0)
            {
                c+=findmax(nums2,val,mid);
            }
            else if(val<0)
            {
               c+=findmin(nums2,val,mid);   
            }
        }
        return c>=k;
    }
    ll findmax(vector<int>& nums2,ll val,long long k)
    {
        ll low=0,high=nums2.size()-1,ans=-1;
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            if(val*nums2[mid]<=k)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans+1;
    }
    ll findmin(vector<int>& nums2,ll val,long long k)
    {
        ll low=0,high=nums2.size()-1,ans=nums2.size();
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            if(val*1ll*nums2[mid]<=k)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return nums2.size()-ans;
    }
    
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll low=-1e10,high=1e10,ans=-1;
        while(low<=high){
            long long mid = low+(high-low)/2;
            
            if(check(mid,nums1,nums2,k)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};