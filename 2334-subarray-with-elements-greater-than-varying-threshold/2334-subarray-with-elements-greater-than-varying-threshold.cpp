class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
         int n=nums.size();  
        vector<int> left(n),right(n);
        stack<int> st;
        for(int i=0;i<n;i++){             
            // for smaller element on left
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(st.empty()) left[i]=-1;
            else left[i]=st.top();
            st.push(i);
        }
       
        st=stack<int>();
        for(int i=n-1;i>=0;i--){                     
            // for smaller element on right
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(st.empty()) right[i]=n;
            else right[i]=st.top();
            st.push(i);
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            int k = (right[i]-left[i]-1);       // length for which the current element is smaller
            double z = (1.0*threshold)/(1.0*k);       
            if(1.0*nums[i]>z) return k;         // if condition satisfies for smaller element then just return length
        }
        return -1;
    }
};