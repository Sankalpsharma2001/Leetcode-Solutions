#define ll long long
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
         int x = 0, y = 0;
        ll a=0,b=0;
        int mod=1e9+7;
        while(x<n && y<m)
        {
            if(nums1[x]<nums2[y])
            {
                a=(a+nums1[x]);
                x++;
                
            }
            else if(nums1[x]>nums2[y])
            {
                b=(b+nums2[y]);
                y++;
            }
            else
            {
                a=b=(max(a,b)+nums1[x]);
                x++;
                y++;
            }
        }
        while(x <n) a =(a+ nums1[x++]);
        while(y < m) b = (b+nums2[y++]);
    return max(a,b)%mod;
    }
};