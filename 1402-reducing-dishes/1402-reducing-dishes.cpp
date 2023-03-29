class Solution {
public:
   
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        int ans=0,s=0,mx=0;
       for(int i=n-1;i>=0;i--)
       {
           s+=satisfaction[i];
           mx+=s;
           ans=max(ans,mx);
       }
        return ans;
        
    }
};