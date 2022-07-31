class NumArray {
public:
    int n;
    vector<int> farr;
        vector<int>pre;
   
    NumArray(vector<int>& nums) {
         n=nums.size();
       pre.resize(n+1);
        farr.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+nums[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            int idesh=i-(i&-i);
            farr[i]=pre[i]-pre[idesh];
        }
        
    }

    void update(int index, int val) {
        index+=1;
        int x=sumRange(index-1,index-1);
        int delta=val-x;
        
        farr[index]+=delta;
        index+=(index&-index);
        while(index<=n)
        {
            farr[index]+=delta;
            index+=(index&-index);
            
        }
        
    }
    
    int sumRange(int left, int right) {
              int i=right+1;
        int rsum=0,lsum=0;
        while(i>0)
        {
            rsum+=farr[i];
            i-=(i&-i);
        }
        
         i=left;
        while(i>0)
        {
            lsum+=farr[i];
            i-=(i&-i);
        }
        return rsum-lsum;
    }
};