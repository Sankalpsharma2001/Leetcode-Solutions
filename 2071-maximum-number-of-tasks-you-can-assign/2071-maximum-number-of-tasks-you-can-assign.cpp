class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers,int maxTask, int pills, int strength)
    {
        multiset<int> w(workers.end()-maxTask,workers.end());
        for(int i=maxTask-1;i>=0;i--)
        {
            auto it=w.end();
            --it;
            if(*it<tasks[i])
            {
                if(pills<=0) return false;
                it=w.lower_bound(tasks[i]-strength);
                if(it==w.end())
                    return false;
                pills--;
            }
            w.erase(it);
            
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int low=0,high=min(workers.size(),tasks.size()),ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(tasks,workers,mid,pills,strength))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};