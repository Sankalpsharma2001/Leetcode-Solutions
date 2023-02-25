class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len=citations.size();
         int low=0,high=len-1,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(len-mid<=citations[mid])
            {
                ans=len-mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};