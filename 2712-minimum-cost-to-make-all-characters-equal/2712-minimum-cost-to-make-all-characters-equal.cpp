#define ll long long
class Solution {
public:
    long long minimumCost(string s) {
     int n = s.size();
        int mid = n / 2;
        long long ans = 0;
        char target = s[mid]; 
        //we will make all chars of string equal to target
        
        int i = mid - 1, j = mid + 1;
        int leftOp = 0, rightOp = 0;
        while(i >= 0)
        {
            char ch = s[i];
            if (leftOp % 2 != 0) //if odd operations done, FLIP CHAR
                ch = (ch == '0')? '1' : '0';
            
            if (ch != target) 
            {
                leftOp++;
                ans += (i + 1);
            }
            i--;
        }
        while(j < n)
        {
            char ch = s[j];
            if (rightOp % 2 != 0) //if odd operations done, FLIP CHAR
                ch = (ch == '0')? '1' : '0';
            
            if (ch != target)
            {
                rightOp++; 
                ans += (n - j);
            }
            j++;
        }
               return ans;
    }
};