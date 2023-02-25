/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
   
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int low=1,high=n-2;
        int h=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid-1)<mountainArr.get(mid) && mountainArr.get(mid+1)<mountainArr.get(mid))
            {
                h=mid;
                break;
            }
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        // cout<<h<<" ";
        if(target==mountainArr.get(h))
         return h;
       low=0,high=h-1;
         while(low<=high)
        {
            int mid=low+(high-low)/2;
           
            if(mountainArr.get(mid)<target)
            {
                low=mid+1;
            }
            else if(mountainArr.get(mid)>target)
            {
                high=mid-1;
            }
             else
                 return mid;
        }
         low=h+1,high=n-1;
         while(low<=high)
        {
            int mid=low+(high-low)/2;
           
            if(mountainArr.get(mid)>target)
            {
                low=mid+1;
            }
            else if(mountainArr.get(mid)<target)
            {
                high=mid-1;
            }
             else
                 return mid;
        }
        
        
            return -1;
    }
};