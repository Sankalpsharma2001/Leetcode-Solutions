class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
       
        int len=citations.size();
//         for(int i=0;i<citations.size();i++)
//         {
//             if(len-i<=citations[i])
//             {
//                 return len-i;
//             }
           
//         }
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