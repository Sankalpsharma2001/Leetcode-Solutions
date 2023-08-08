class Solution {
public:
       vector<long long int> findl(vector<int>& arr,int n)
    {
        vector<long long int> v(n);
        stack<int> s;
        s.push(0);
        v[0]=1;
        for(int i=1;i<n;i++)
        {
            while(!s.empty() and arr[s.top()]>arr[i]) 
            s.pop();
            if(s.empty())
            v[i]=i+1;
            else
            v[i]=i-s.top();
            s.push(i);
        }
        return v;
    }
    vector<long long int> findr(vector<int>& arr,int n)
    {
        vector<long long int> v(n);
        stack<int> s;
        s.push(n-1);
        v[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() and arr[s.top()]>=arr[i])
            s.pop();
            if(s.empty())
            v[i]=n-i;
            else
            v[i]=s.top()-i;
            s.push(i);
        }
        return v;
    }
    int sumSubarrayMins(vector<int>& arr) {
      ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        // [71,55,82,55] in this case we r counting 55 82 55 2 times so when we are finding left min we will do > not equal to remove this case
        int mod=1e9+7;
        long long ans=0;
        int n=arr.size();
        vector<long long int> left=findl(arr,n);
        vector<long long int> right=findr(arr,n);
       for(int i=0;i<n;i++)
       {long long int l=(left[i]);
        long long int r=right[i];
          ans=ans%mod+((arr[i]*l*r*1ll)%mod);  
        // cout<<l<<" "<<r<<endl;
       }
    return ans%mod;
    }
};