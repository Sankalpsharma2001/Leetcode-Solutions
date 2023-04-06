#define ll long long
class Solution {
public:
    class Compare {
public:
    bool operator()(pair<ll,ll> below, pair<ll,ll> above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second > above.second) {
            return true;
        }
 
        return false;
    }
};
    int shortestSubarray(vector<int>& nums, int k) {
      int n=nums.size();
       priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        
       // priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,Compare> pq;
        ll sum=0,ans=1e6;
       for(ll i=0;i<n;i++)
       {
           sum+=nums[i];
           if(sum>=k)
           {
               ans=min(ans,i+1);
               
           }
           while(!pq.empty() && sum-pq.top().first>=k)
           {
               ans=min(ans,i-pq.top().second);
               pq.pop();
           }
           pq.push({sum,i});
       }
        return ans==1e6?-1:ans;
    }
};