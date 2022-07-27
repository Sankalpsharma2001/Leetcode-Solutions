class Solution {
public:
    struct com{
        bool operator()(pair<int,string> a,pair<int,string> b)
        {
            if(a.first!=b.first)
            {
                return a.first>b.first;
            }
            else
            {
                 return a.second<b.second;
            }
        }
    };
 
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> m;
        for(auto x:words)
            m[x]++;
       
     priority_queue<pair<int,string>,vector<pair<int,string>>,com> pq;
    for(auto x:m)
    {
          pq.push({x.second,x.first});
        if(pq.size()>k)
        {
             pq.pop();
        }
         
    }
     while(!pq.empty())
     {
         ans.push_back(pq.top().second);
         pq.pop();
     }
      reverse(ans.begin(),ans.end());  
       
        
        return ans;
    }
};