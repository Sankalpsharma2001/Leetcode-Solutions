class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> t;
        t=arr;
        sort(t.begin(),t.end());
        long long int ans=0,mx=-1,sum1=0,sum2=0;
        for(int i=0;i<arr.size();i++)
        {
           sum1+=arr[i];
            sum2+=t[i];
            if(sum1==sum2)
                ans++;
        }
        return ans;
    }
};