class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int s=nums[0];
        if(n==1) return 0;
        int jumpTotal=0,i=0,mx=0;
        while(i<n-1)
        {
            s=max(s,nums[i]+i);
           
            if(i==mx)
            {
                jumpTotal++;
                mx=s;
            }
            i++;
        }
        return jumpTotal;
    }
};