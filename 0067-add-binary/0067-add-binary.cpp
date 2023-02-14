class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size()-1,j=b.size()-1;
        int sum=0,carry=0;
        while(i>=0 && j>=0)
        {
            sum=(a[i]-'0'+b[j]-'0')+carry;
             if(sum>1) carry=1;
            else carry=0;
            ans+=to_string(sum%2);
            i--,j--;
        }
        while(i>=0)
        {
            sum=a[i]-'0'+carry;
            if(sum>1) carry=1;
            else carry=0;
             ans+=to_string(sum%2);
            i--;
        }
        while(j>=0)
        {
            sum=b[j]-'0'+carry;
            if(sum>1) carry=1;
            else carry=0;
             ans+=to_string(sum%2);
            j--;
        }
        if(carry)
        {
            ans+=to_string(carry%2);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};