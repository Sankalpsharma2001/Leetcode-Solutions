class Solution {
public:
   double mediann(vector<int>&a,vector<int>&b){
        int m=a.size();
        int n=b.size();
        if(m>n)
            return mediann(b,a);
        int l=0,r=m;
        while(l<=r){
            int partx=l+(r-l)/2;    
            int party=(m+n+1)/2-partx;
            int left1=(partx==0)?INT_MIN:a[partx-1];
            int right1=(partx==m)?INT_MAX:a[partx];
            int left2=(party==0)?INT_MIN:b[party-1];
            int right2=(party==n)?INT_MAX:b[party];
            if(left1<=right2&&left2<=right1){
                if((m+n)%2==0)
                    return (double)(max(left1,left2)+min(right1,right2))/2;
                else
                    return (double)(max(left1,left2));
            }else if(left1>right2)
                r=partx-1;
            else
                l=partx+1;
        }
        return -1.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        ans=mediann(nums1,nums2);
        return ans;   
    }

};