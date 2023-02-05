class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
       int n=s.size();
        int m=p.size(); 
        vector<int> freqP(26,0);
        vector<int> freqS(26,0);
        if(m>n) return ans;
       for(int i=0;i<m;i++)
       {
           freqS[s[i]-'a']++;
           freqP[p[i]-'a']++;
       }
        int j=m,i=0;
         if(freqP==freqS)
            {
                ans.push_back(0);
            }
        while(j<n)
        {
            
           freqS[s[j]-'a']++;
            freqS[s[i]-'a']--;
           
           
             j++;
            
            i++;
             if(freqP==freqS) ans.push_back(i);
        }
        return ans;
    }
};