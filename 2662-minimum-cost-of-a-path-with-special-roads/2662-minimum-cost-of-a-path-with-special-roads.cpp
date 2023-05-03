class Solution {
public:
    int minimumCost(vector<int>& s, vector<int>& t, vector<vector<int>>& sp) {
        
        int x=t[0],y=t[1];
        int i=s[0],j=s[1];
        int ans=(abs(x-i)+abs(y-j));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{i,j}});
      map<pair<int,int>,int> dis;
        dis[{i,j}]=0;
         for(auto it:sp)
            dis[{it[2],it[3]}]=INT_MAX;
        
        
        while(!pq.empty())
        {
                auto t=pq.top();
                pq.pop();
            int c=t.first;
            i=t.second.first,j=t.second.second;
            if(i==x && j==y) return min(c,ans);
             pq.push({c+abs(i-x)+abs(j-y),{x,y}});
                for(int idx=0;idx<sp.size();idx++)
                {   
                    if(sp[idx][2]==i && sp[idx][3]==j) continue;
                    int fx=abs(sp[idx][0]-i),fy=abs(sp[idx][1]-j);
                    int ex=sp[idx][2],ey=sp[idx][3];
                    int d=sp[idx][4];
                   if(dis[{ex,ey}]>c+fx+fy+d)
                   {dis[{sp[idx][2],sp[idx][3]}]=c+fx+fy+d;
                    pq.push({c+fx+fy+d,{sp[idx][2],sp[idx][3]}});
                   }
                }
            
        }
        return 0;
    }
};