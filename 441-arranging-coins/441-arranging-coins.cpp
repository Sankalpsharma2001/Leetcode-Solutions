class Solution {
public:
    int arrangeCoins(int n) {
       int l = 1, r = n, ans;
		long mid, coinsNeeded;
        while(l <= r) {
          long mid = l + ((r-l) >> 1);                           
            coinsNeeded = (mid * (mid + 1)) >> 1;             
            
            if(coinsNeeded <= n) l = mid + 1, ans = mid;      
            else r =mid - 1;                                  
        }
        return ans;
    }
};