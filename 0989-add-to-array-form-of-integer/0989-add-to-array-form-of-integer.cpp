class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        long long int n=0;
        string str="";
        for(int i=0;i<num.size();i++)
        {
           str+=num[i]+'0';
        }
        string str1=to_string(k);
       int i=str.size()-1,j=str1.size()-1;
        int idx=0,carry=0;
        vector<int> ans;
        while(i>=0 || j>=0 || carry)
        {
            int sum=carry;
            if(i>=0)
            {
                sum+=str[i--]-'0';
            }
            if(j>=0)
            {
                sum+=str1[j--]-'0';
            }
            // cout<<sum<<" ";
            carry=sum/10;
           
              ans.push_back(sum%10);  
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};