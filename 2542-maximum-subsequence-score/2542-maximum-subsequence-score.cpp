
#define ll long long 
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
       int n=nums1.size();
        vector<pair<ll,ll>> p;
        for(int i=0;i<nums1.size();i++)
        {
            p.push_back(make_pair(nums2[i],nums1[i]));
            
        }
        // when we are multiplying we should have to get large value so we are sorting in nums2 from large value to small 
        sort(p.rbegin(),p.rend());
       priority_queue<int, vector<int>, greater<int>> pq; // min pq
        ll s=0,ans=0;
        for(int i=0;i<n;i++)
        {
            pq.push(p[i].second);
            s+=p[i].second;
            if(pq.size()>k)
            {
                s-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
            {
                ans=max(ans,p[i].first*s);
            }
        }
       return ans;
       
        
    }
};