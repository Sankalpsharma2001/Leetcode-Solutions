class Solution {
public:
    bool solve(vector<int> &jobs,int idx,int &target,vector<int> &sum)
    {
        if(idx==jobs.size()) return true;
      
        for(int i=0;i<sum.size();i++)
        {
            sum[i]+=jobs[idx];
            if(sum[i]<=target && solve(jobs,idx+1,target,sum))
                return true;
            sum[i]-=jobs[idx];
            // if any of the worker doesn't get any job then this combination will not produce optimal result
             if(sum[i]==0)
            {
                return false;
            }
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int &k) {
        sort(jobs.rbegin(),jobs.rend());
        int low=jobs[0],high=1e9;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            vector<int> sum(k,0);
            if(solve(jobs,0,mid,sum))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};