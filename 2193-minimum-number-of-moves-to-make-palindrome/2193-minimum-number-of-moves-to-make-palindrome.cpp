class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1,ans=0;
        while(i<j)
        {
            int l=i,r=j;
            while(s[l]!=s[r])
            {
                r--;
            }
            int l1=i,r1=j;
            while(s[l1]!=s[r1]){
                l1++;
            }
            if(l==r && l1==r1)
            {
                // this is present only 1 times means
                ans++;
                swap(s[r],s[r+1]);
                continue;
            }
            else
            {
                if(l1-i>j-r)
                {
                while(r<j)
                {
                    swap(s[r],s[r+1]);
                    r++;
                    ans++;
                }
                }
                else
                {
                    while(i<l1)
                    {
                        swap(s[l1],s[l1-1]);
                        l1--;
                        ans++;
                    }
                }
            }
            
           i++;
            j--;
            
        }
        return ans;
    }
};