class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
         int ans=0;
      
        for(int i=0;i<n;i++)
        {
          int contribution=((i+1)*(n-i)+1)/2;
          ans+=(arr[i]*contribution);
            
        }
        return ans;
    }
};