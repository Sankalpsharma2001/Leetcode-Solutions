class Solution {
public:
    int precedence(char s)
    {
        if(s=='+' || s=='-')
            return 1;
         if(s=='*' || s=='/')
            return 2;
        else
            return 0;
    }
    int perform(int a,int b,char op)
    {
        if(op=='+')
            return a+b;
        if(op=='-')
            return a-b;
        if(op=='*')
            return a*b;
       if(op=='/')
            return a/b;
        return 0;
    }
    int calculate(string s) {
        stack<char> ar;
        stack<int> val;
        long long int n=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')continue;
            if(isdigit(s[i]))
            {
               n=0;
                while(i<s.size() and isdigit(s[i]))
                {
                    n=n*10+s[i]-'0';
                    i++;
                }
                val.push(n);
                i--;
            }
            else
            {
              while(!ar.empty() and precedence(ar.top())>=precedence(s[i]))
              {
                  int val2=val.top();
                  val.pop();
                  int val1=val.top();
                  val.pop();
                  char c=ar.top();
                  ar.pop();
                  int x=perform(val1,val2,c);
                  val.push(x);
              }
                ar.push(s[i]);
            }
        }
        while(!ar.empty())
        {
                  int val2=val.top();
                  val.pop();
                  int val1=val.top();
                  val.pop();
                  char c=ar.top();
                  ar.pop();
                  int x=perform(val1,val2,c);
                  val.push(x);
        }
        return val.top();
    }
};