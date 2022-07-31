class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
      int low=0,high=grades.size();
        int n=grades.size(),ans=1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(1ll*mid*(mid+1)/2<=n)
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};