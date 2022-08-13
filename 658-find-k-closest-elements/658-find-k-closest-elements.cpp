class Solution {
public:
    int find(vector<int> &arr,int low,int high,int x)
{
    if(arr[high]<=x)
    return high;
    if(arr[low]>x)
    return low;
    int mid=low+(high-low)/2;
    if(arr[mid]<=x and arr[mid+1]>x)
    return mid;
    if(arr[mid]<x)
    return find(arr,mid+1,high,x);
    return find(arr,low,mid-1,x);
    
}
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		// int n = size(arr), R = lower_bound(begin(arr), end(arr), x) - begin(arr), L = R - 1;
		// // expand the [L, R] window till its size becomes equal to k
		// while(k--) 
		// if(R >= n || L >= 0 && x - arr[L] <= arr[R] - x) L--;  // expand from left
		// else R++;                                              // expand from right
		// return vector<int>(begin(arr) + L + 1, begin(arr) + R);
       int n=arr.size();
        int l=find(arr,0,n-1,x);
        int r=l+1;
       
        int c=0;
        vector<int> ans;
        while(l>=0 and r<n and c<k)
        {
            if(x-arr[l]<=arr[r]-x)
            {
                ans.push_back(arr[l]);
                l--;
            }
            else
            {
                ans.push_back(arr[r]);
                r++;
            }
            c++;
        }
        while(c<k and l>=0)
        {
            ans.push_back(arr[l]);
                l--;
                c++;
        }
        while(c<k and r<n)
        {
             ans.push_back(arr[r]);
                r++;
                c++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};