class Solution {
public:
    int lengthOfLastWord(string s) {
       int ans=0;
        for(int i=0;i<s.size();i++)
        {
         if(s[i]==' ') continue;
         string str="";
            int j=i,c=0;
            while(j<s.size() &&  s[j]!=' ')
            {
                c++;j++;
            }
            ans=c;
            i=j;
        }
        return ans;
    }
};