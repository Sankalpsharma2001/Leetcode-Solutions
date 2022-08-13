class Solution {
public:
    void merge(vector<int> &nums,int l,int m,int r)
    {
         int n1 = m - l + 1;
    int n2 = r - m;
    int A[n1], B[n2];
    
    for(int i = 0; i < n1; i++)
        A[i] = nums[l + i];
    
    for(int i = 0; i < n2; i++)
        B[i] = nums[m + 1 + i];
    
    int i = 0, j = 0;
    int k = l;
    
    while(i < n1 && j < n2)
    {
        if(A[i] <= B[j])
            nums[k++] = A[i++];
        else
            nums[k++] = B[j++];
    }
    
    while(i < n1)
        nums[k++] = A[i++];
    while(j < n2)
        nums[k++] = B[j++];
        
        // int i=low,j=mid+1,k=low;
        // vector<int> temp(high+1);
        // while(i<=mid && j<=high)
        // {
        //     if(nums[i]<nums[j])
        //     {
        //         temp[k++]=nums[i++];
        //     }
        //     else
        //     {
        //         temp[k++]=nums[j++];
        //     }
        // }
        // while(i<=mid)
        // {
        //     temp[k++]=nums[i++];
        // }
        // while(j<=high)
        // {
        //     temp[k++]=nums[j++];
        // }
        // for(int x=low;x<=high;x++)
        // {
        //   nums[x]=temp[x];   
        // }
    }
    void mergesort(vector<int> &nums,int low,int high)
    {
        if(low<high)
        {
         int mid=low+(high-low)/2;
            mergesort(nums,low,mid);
            mergesort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
      mergesort(nums,0,nums.size()-1);  
        return nums;
    }
};