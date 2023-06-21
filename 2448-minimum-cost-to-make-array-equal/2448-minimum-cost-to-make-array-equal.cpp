class Solution {
public:
    long long findSum(vector<int>& nums, vector<int>& cost,long long mid)
    {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            long long x=abs(nums[i]-mid);
            sum+=(x*cost[i]);
        }
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long low=0,high=1e6;
       
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            long long a=findSum(nums,cost,mid);
            long long b=findSum(nums,cost,mid-1);
            long long c=findSum(nums,cost,mid+1);
           
            if(a<=b && a<=c)
            {
                return a;
            }
            if(a>c)
            {
                
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return 0;
    }
};