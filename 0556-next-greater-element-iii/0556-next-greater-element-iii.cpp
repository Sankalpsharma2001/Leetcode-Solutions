class Solution {
public:
    bool nextPermutation(string &s)
    {
        int i=s.size()-1;
        while(i>0 && s[i-1]>=s[i]) i--;
        if(i==0) return false;
        
        //1 3 2 it will stop at 3 so we do i--
        i--;
        int j=s.size()-1;
        while(j>=0 && s[i]>=s[j])j--;
        swap(s[j],s[i]);
        reverse(s.begin()+i+1,s.end());
        return true;
    }
    int nextGreaterElement(int n) {
       string s=to_string(n);
       bool flag=nextPermutation(s); 
        long long ans=stoll(s);
       if(flag==true && ans<=INT_MAX) return ans;
        return -1;
        
    }
};