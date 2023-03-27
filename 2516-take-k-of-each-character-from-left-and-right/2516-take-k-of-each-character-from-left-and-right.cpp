class Solution {
public:
    int takeCharacters(string s, int k) {
       unordered_map<char,int> m;
        for(auto &it:s)
        {
            m[it]++;
        }
        int a=m['a'],b=m['b'],c=m['c'];
        if(a<k || b<k || c<k) return -1;
        int aa=a-k,bb=b-k,cc=c-k;
        
        m.clear();
        int i=0,j=0,mx=0;
        while(i<s.size())
        {
           m[s[i]]++;
            
                while(j<=i && ( m['a']>aa || m['b']>bb || m['c']>cc))
                {
                  
                    m[s[j]]--;
                      j++;
                }
                // cout<<i<<" "<<j<<endl;
                mx=max(mx,i-j+1);
            
            i++;
            
        }
        return s.size()-mx;
    }
};