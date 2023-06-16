class Solution {
public:
    int lengthOfLongestSubstring(string s) {
             if(s.length()==0)return 0;   
        unordered_map<char,int> m;  
        int n=s.size();
      int left=0,right=0;
        int ans=-1e9;
        while(right<n)
        {
            if(m.find(s[right])!=m.end())
            {
              left=max(left,m[s[right]]+1);    
            }
            ans=max(ans,right-left+1);
            m[s[right]]=right;
            right++;
        }
        return ans;
    }
};