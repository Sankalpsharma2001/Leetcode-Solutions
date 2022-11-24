class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int i=0,mx=0,ans=0;
        for(int j=0;j<arr.size();j++)
        {
            mx=max(mx,arr[j]);
            if(mx==j)
                ans++;
            
        }
        return ans;
    }
};