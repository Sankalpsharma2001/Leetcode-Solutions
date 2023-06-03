class Solution {
public:
     vector<long long int> findl(vector<int>& arr,int n)
    {
        vector<long long int> v(n);
        stack<int> s;
       
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and arr[s.top()]>=arr[i])
            s.pop();
            if(s.empty())
            v[i]=0;
            else
            v[i]=s.top()+1;
            s.push(i);
        }
        return v;
    }
    vector<long long int> findr(vector<int>& arr,int n)
    {
        vector<long long int> v(n,n);
        stack<int> s;
       
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() and arr[s.top()]>=arr[i])
            s.pop();
            if(s.empty())
            v[i]=n-1;
            else
            v[i]=s.top()-1;
            s.push(i);
        }
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
      long long ans=0;
        int n=heights.size();
//         vector<long long int> left=findl(heights,n);
//         vector<long long int> right=findr(heights,n);
      
//         for(int i=0;i<n;i++)
//         { long long val=heights[i]*(right[i]-left[i]+1);
//             ans=max(ans,val);
//             // cout<<ans<<" ";
//         }
//         return ans;   
        // single pass 
         stack < int > st;
      int maxA = 0;
    
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
          int height = heights[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
};