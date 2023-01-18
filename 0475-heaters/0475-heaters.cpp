class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
      sort(heaters.begin(),heaters.end());
        int ans=0;
      for(int i=0;i<houses.size();i++)
      {
          auto it=lower_bound(heaters.begin(),heaters.end(),houses[i]);
          int r=INT_MAX;
          // farther
          if(it!=heaters.end())
          {
              r=*it-houses[i];
          }
          //previous
          if(it!=heaters.begin())
          {
              auto s=it-1;
              r=min(r,houses[i]-*s);
          }
          ans=max(ans,r);
      }
        return ans;
        
        
        
    }
};