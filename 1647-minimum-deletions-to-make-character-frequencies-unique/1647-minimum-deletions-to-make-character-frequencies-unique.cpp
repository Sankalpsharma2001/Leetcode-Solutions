class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        sort(freq.begin(),freq.end());
        int ans=0;
        for(int i=24;i>=0;i--)
        {
            if(freq[i]==0) continue;
            if(freq[i]>=freq[i+1])
            {
                int prev=freq[i];
                freq[i]=max(0,freq[i+1]-1);
                ans+=prev-freq[i];
            }
            
            
        }
        return ans;
        
        
    }
};