class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
      int ans=0;
        for(int i=0;i<n;i++)
        {
              vector<int> freq(26,0);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                int mn=INT_MAX,mx=INT_MIN;
                for(int k=0;k<26;k++)
                {
                    if(freq[k]==0) continue;
                    mn=min(mn,freq[k]);
                    mx=max(mx,freq[k]);
                }
                if(mx-mn>0 )
                    ans+=mx-mn;
            }
        }
        return ans;
    }
};