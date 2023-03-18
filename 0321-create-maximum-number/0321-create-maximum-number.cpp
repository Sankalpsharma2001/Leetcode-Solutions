class Solution {
public:
    vector<int> solve(vector<int> &nums,int sz)
    {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
             // Pop elements from the stack if current element is greater than head of the stack
            // We can pop only if remaining elements in nums1 + remaining elements in stack 
            // after popping is greater than or equal to k

            while(!ans.empty() && ans.back()<nums[i] && (ans.size()-1+(n-i)>=sz))
            {
                ans.pop_back();
            }
            if(ans.size()<sz)
            ans.push_back(nums[i]);
        }
        return ans;
    }
    void merge(vector<int> &a,vector<int> &b,vector<int> &t)
    {
        int n=a.size();
        int m=b.size();
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(a[i]>b[j])
            {
                t.push_back(a[i]);
                i++;
            }
            else if(a[i]<b[j])
            {
                t.push_back(b[j]);
                j++;
            }
            else
            {
                int x=i,y=j;
                while(x<n && y<m && a[x]==b[y])
                {
                    x++,y++;
                }
                if(y==m)
                {
                    t.push_back(a[i]);
                    i++;
                }
                else if(x==n)
                {
                    t.push_back(b[j]);
                    j++;
                }
                else if(a[x]>b[y])
                { 
                    t.push_back(a[i]);
                    i++;
                }
                else
                {
                    t.push_back(b[j]);
                    j++;
                }
            }
        }
        while(i<n)
        {
            t.push_back(a[i]);
            i++;
        }
        while(j<m)
        {
            t.push_back(b[j]);
            j++;
        }
        
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for(int i=0;i<=k;i++)
        {
            vector<int> a=solve(nums1,i); // take ith size from nums1
            vector<int> b=solve(nums2,k-i); // take k-i size from nums2
            vector<int> t;
            merge(a,b,t);
            if(t.size()==k) ans=max(ans,t);
            
        }
        return ans;
    }
    
};