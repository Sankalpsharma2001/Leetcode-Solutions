class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
     int n=arr.size(),one=0;
      for(auto &it:arr)
      {
          if(it==1) one++;
      }
         
      if(one==0)
          return {0,n-1};
      if(one%3!=0)
          return {-1,-1};
       int x=one/3;
       int c=0;
        int i1=-1,i2=-1,i3=-1;
        // cout<<x<<endl;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1) c++;
           
            if(c==1 && i1==-1){i1=i;}
            if(x+1==c && i2==-1){i2=i;}
           
            if(c==2*x+1 && i3==-1) {i3=i;}
        }
    
        // cout<<i1<<" "<<i2<<" "<<i3<<endl;
        while(i3<n && arr[i1]==arr[i2] && arr[i2]==arr[i3])
        {
            i1++,i2++,i3++;
        }
        if(i3==n)
        {
            return {i1-1,i2};
        }
        return {-1,-1};
        
        
    }
};