class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        string ans="";
        while(i>=0 and j>=0)
        {
            int x=(num1[i]-'0')+(num2[j]-'0')+carry;
            ans+=to_string(x%10);
            carry=x/10;
            i--;
            j--;
        }
        while(i>=0)
        {
          int x=(num1[i]-'0')+carry;
            ans+=to_string(x%10);
            carry=x/10;
            i--;   
        }
         while(j>=0)
        {
          int x=(num2[j]-'0')+carry;
            ans+=to_string(x%10);
            carry=x/10;
            j--;   
        }
        if(carry)
            ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};