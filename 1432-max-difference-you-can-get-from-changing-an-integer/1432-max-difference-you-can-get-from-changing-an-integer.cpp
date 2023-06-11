class Solution {
public:
    int maxDiff(int num) {
        
        string a=to_string(num),b=to_string(num);
        int n=a.size();
        int i=0;
        for(;i<a.size();i++)
        {
            if(a[i]!='9')
            {
                break;
            }
        }
        
        if(i<n)
        {
            char c=a[i];
            for(int j=i;j<n;j++)
            {
                if(c==a[j])
                a[j]='9';
            }
        }
        int n1=stoi(a);
          i=0;
        for(;i<b.size();i++)
        {
            if(b[i]!='0' && b[i]!='1')
            {
                break;
            }
        }
        
        if(i<n)
        {
            char c=b[i];
            char ch;
            if(c==b[0])
            {
                ch='1';
            }
            else
                ch='0';
            
            for(int j=i;j<n;j++)
            {
                if(c==b[j])
                b[j]=ch;
            }
        }
        int n2=stoi(b);
        return n1-n2;
    }
};