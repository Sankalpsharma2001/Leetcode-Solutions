class Solution {
public:
    class com{
        public:
        bool operator()(pair<int,int> &a,pair<int,int> &b)
        {
            if(a.first<b.first) return true;
            else if(a.first==b.first && a.second<b.second) return true;
            return false;
        }
    };
    int findOne(vector<int> &m)
    {
        int low=0,high=m.size()-1,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(m[mid]==0)
            {
                high=mid-1;
            }
            else
            {
                ans=mid+1;
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
         int n=mat.size(),m=mat[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,com> pq;
        for(int i=0;i<n;i++)
        {
            int cnt=findOne(mat[i]);
            pq.push({cnt,i});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
         vector<int> ans(k);
       for(int i=k-1;i>=0;i--)
       {
           ans[i]=pq.top().second;
           pq.pop();
       }
       return ans;
    }
};