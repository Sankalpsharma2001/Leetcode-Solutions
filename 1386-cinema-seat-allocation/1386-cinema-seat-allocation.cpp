class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
       ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
         map<int,vector<int>> m;        
        for(int i=0;i<r.size();i++)
        {
           m[r[i][0]].push_back(r[i][1]);
        }
        int ans=(n-m.size())*2;
       map<int,vector<int>> ::iterator it;
        // for(it=m.begin();it!=m.end();it++)
        for(auto &it:m)
        {
            bool flag=false;
            vector<int> v(11,0);
            vector<int> x=it.second;
            for(int i=0;i<x.size();i++)
                v[x[i]]=1;
            // for(auto x:it->second)
            // {
            //     v[x]=1;
            // }
            if(!v[2] and !v[3] and !v[4] and !v[5])
            {
                ans++;
                flag=true;
            }
            if(!v[6] and !v[7] and !v[8] and !v[9])
            {
                ans++;
                flag=true;
            }
            if(!flag and !v[4] and !v[5] and !v[6] and !v[7])
            {
                ans++;
                flag=true;
            }
        }
        return ans;
    }
};