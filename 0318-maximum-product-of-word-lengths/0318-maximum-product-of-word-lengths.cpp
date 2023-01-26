class Solution {
public:
    int getDecimalValue(string &s)
    {
        int num=0;
        for(char &c:s)
        {
            num|=(1<<(c-'a'));
        }
        return num;
    }
    int maxProduct(vector<string>& words) {
      int ans=0;
        int n=words.size();
        vector<int> storeBitValue(n);
        for(int i=0;i<n;i++)
        {
            storeBitValue[i]=getDecimalValue(words[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               if((storeBitValue[i]&storeBitValue[j])==0)
               {
                  ans=max(ans,(int)words[i].size()*(int)words[j].size());
               }
            }    
                
        }
        return ans;
    }
    
};