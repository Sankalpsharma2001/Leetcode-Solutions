class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2) return n;
        int ans=1;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0],y=points[i][1];
            unordered_map<double,int> m;
            for(int j=0;j<points.size();j++)
            {
                if(i==j) continue;
                 int x1=points[j][0],y1=points[j][1];
                
                double s;
                if(x==x1)
                {
                     m[INT_MAX]++;
                }
                else
                {
                    s=(double)((y-y1)*1.0)/((x-x1)*1.0);
                    // cout<<s<<" ";
                  m[s]++;  
                }
            }
            for(auto &it:m)
            {
                // cout<<it.first<<" "<<it.second<<endl;
                ans=max(ans,it.second+1);
            }
        }
        return ans;
    }
};