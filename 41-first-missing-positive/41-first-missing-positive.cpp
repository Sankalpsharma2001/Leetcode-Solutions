class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
       int n=A.size();
    for(int i=0;i<n;)
    {
        if(A[i]<=0 || A[i]>n ) {i++;continue;}
        if(A[i]!=A[A[i]-1])
        swap(A[i],A[A[i]-1]);
        else
        i++;
        /*while(A[i]>0 and A[i]<=n and A[i]!=A[A[i]-1])
        {
            swap(A[i],A[A[i]-1]);
        }*/
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]!=i+1)
        return i+1;
    }
    return n+1;    
    }
};