class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        
        unordered_map<char,int> mp;
        int ans=1;
        for(int i=0;i<n;i++)
        {
         mp[s[i]]++;
            if(mp[s[i]]>1)
            {
                mp.clear();
                mp[s[i]]++;
                ans++;
            }
            
        }
        return ans;
    }
};