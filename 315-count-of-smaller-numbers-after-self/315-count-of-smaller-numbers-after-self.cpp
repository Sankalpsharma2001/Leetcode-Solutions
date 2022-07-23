class Solution {
public:
    void merge(vector<int> &c,vector<pair<int,int>> &p,int low,int mid,int high)
    {
        vector<pair<int,int>> t(high-low+1);
        int i=low;
        int j=mid+1;
        int k=0;
        while(i<=mid and j<=high)
        {
            if(p[i].first<=p[j].first)
            {
                t[k++]=p[j++];
            }
            else
            {
                c[p[i].second]+=high-j+1;
                t[k++]=p[i++];
            }
            
        }
        while(i<=mid)
        {
            t[k++]=p[i++];
        }
        while(j<=high)
        {
            t[k++]=p[j++];
        }
        for( i=low;i<=high;i++)
        {
            p[i]=t[i-low];
        }
    }
    void mergesort(vector<int> &c,vector<pair<int,int>> &p,int low,int high)
    {
        int mid=(low+high)/2;
            if(low<high)
            {
                mergesort(c,p,low,mid);
                mergesort(c,p,mid+1,high);
                merge(c,p,low,mid,high);
            }
    }
   
    vector<int> countSmaller(vector<int>& nums) {
       ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        vector<pair<int,int>> p;
          for(int i=0;i<nums.size();i++)
        {
            p.push_back({nums[i],i});
        }
        vector<int> c(n,0);
          mergesort(c,p,0,nums.size()-1);
        return c;
    }
};