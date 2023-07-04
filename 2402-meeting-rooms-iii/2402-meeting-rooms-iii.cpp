#define ll long long
class Solution {
public:
    int mostBooked(int &n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<ll> freq(n,0);
        priority_queue<ll,vector<ll>,greater<ll>> empty;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> occupy;
        for(int i=0;i<n;i++)
            empty.push(i);
        
        for(auto &m:meetings)
        {
            int start=m[0];
            while(occupy.size())
            {
                if(start<occupy.top().first)
                {
                    break;
                }
                int avlroom=occupy.top().second;
                occupy.pop();
                empty.push(avlroom);
            }
            int room=-1;
            if(empty.size())
            {
                room=empty.top();
                empty.pop();
               
                occupy.push({m[1],room});
            }
            else if(occupy.size())
            {
                room=occupy.top().second;
                ll end=occupy.top().first+m[1]-m[0];
                occupy.pop();
                occupy.push({end,room});
            }
            if(room!=-1)
                freq[room]++;
        }
       int idx=-1,mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(freq[i]>mx)
            {
                mx=freq[i];
                idx=i;
            }
            
        }
        return idx;
    }
};