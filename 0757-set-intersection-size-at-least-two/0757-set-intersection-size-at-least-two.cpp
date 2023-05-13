class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
          if(a[1]!=b[1])
              return a[1]<b[1];
           else
               return a[0]>b[0];
       });
        int ans=0;
        int n=intervals.size();
        int x=-1,y=-1;
        for(auto &it:intervals)
        {
            if(it[0]<=x) continue;
            if(it[0]>y)
            {
                y=it[1];
                x=it[1]-1;
                ans+=2;
            }
            else
            {
                x=y;
                y=it[1];
                ans++;
            }    
        }
        return ans;
    }
};