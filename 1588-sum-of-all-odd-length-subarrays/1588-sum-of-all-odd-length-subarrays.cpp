class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int> pre(n+1,0);
        pre[0]=0;
         int ans=0;
       
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+arr[i];
           
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if((j-i+1)%2)
                {
                    ans+=pre[j+1]-pre[i];
                }
            }
            
        }
        return ans;
    }
};