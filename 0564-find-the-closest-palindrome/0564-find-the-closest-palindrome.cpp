class Solution {
public:
//     For any possible number, there is 5 cases:
// Say the number is 4723

// Case 1. The next closest palidrome has one digit extra : So here it will be 10001
// Case 2. The next closest palindrome has one digit less: So here it will be 999
// Case 3. The next closest palidrome has the same number of digits
// For case 3 there are 3 subcases:
// -The middle digit remains same.Postfix is the mirror image of prefix. So here 47(prefix)74(postfix)-->4774
// -The middle digit increases by 1.Postfix is the mirror image of prefix. So here 4884
// -The middle digit decreases by 1.Postfix is the mirror image of prefix. So here 4664
// Among these 5 candidates:
// The candidate having the least absolute difference from the original number is the answer. In this case it is 4774.
    string nearestPalindromic(string n) {
         if(n.length()==1) return to_string(stoi(n)-1);
        
   int digits=n.length();
          vector<long>ans;
   ans.push_back(pow(10,digits-1)-1);//Case 1
   ans.push_back(pow(10,digits)+1);//Case 2
   int mid=(digits+1)/2;
      long prefix=stol(n.substr(0,mid));
         vector<long>v={prefix,prefix+1,prefix-1};
        for(auto &it:v)
        {
            string postfix=to_string(it);
            if(digits%2) postfix.pop_back();
            reverse(postfix.begin(),postfix.end());
            string res=to_string(it)+postfix;
            ans.push_back(stol(res));
            
            
        }
        long num=stol(n),mn=LONG_MAX,res;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]!=num && abs(num-ans[i])<mn)
            {
                mn=abs(num-ans[i]);
                res=ans[i];
            }
            else if(abs(num-ans[i])==mn)
            {
                res=min(res,ans[i]);
            }
        }
        return to_string(res);
        
        
        
    }
};