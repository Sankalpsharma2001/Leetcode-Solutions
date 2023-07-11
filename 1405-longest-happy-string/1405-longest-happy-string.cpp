class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int n=a+b+c;
        string ans="";
        int ca=0,cb=0,cc=0;
        for(int i=0;i<n;i++)
        {
            if((a>=b && a>=c && ca!=2) || (a>0 && cb==2) || (a>0 && cc==2))
            {
                ans+='a';
                ca++;
                cb=cc=0;
                a--;
            }
            else if(b>=a && b>=c && cb!=2 ||  (b>0 && ca==2) || (b>0 && cc==2))
            {
                ans+='b';
                cb++;
                ca=cc=0;
                b--;
            }
            else if(c>=a && c>=b && cc!=2 ||  (c>0 && cb==2) || (c>0 && ca==2))
            {
                ans+='c';
                cc++;
                ca=cb=0;
                c--;
            }
        }
        
        return ans;
    }
};