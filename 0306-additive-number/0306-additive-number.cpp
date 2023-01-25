class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n=num.size();
        for(int i=1;i<n;i++)
        {
             string a=num.substr(0,i);
            if(a.size()>1 && a[0]=='0') break;
            for(int j=i+1;j<n;j++)
            {
               string b=num.substr(i,j-i);
               if(b.size()>1 && b[0]=='0') break;
               long x=stol(a),y=stol(b);
               long z=x+y;
               string next=to_string(z);
               string check=a+b+next;
                while(check.size()<num.size())
                {
                    x=y;
                    y=z;
                    z=x+y;
                    next=to_string(z);
                    check+=next;
                    
                }
                if(check==num) return true;
                
            }
        }
        return false;
    }
 
};