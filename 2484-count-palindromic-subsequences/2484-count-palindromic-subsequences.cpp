class Solution {
public:
    // <index, length, first_num, second_num>
    int dp[10001][6][10][10];
    int MOD = 1e9+7;
      int topDown(int i, int len, int a, int b, string &s){
        if(len == 5){
            return 1;
        }
        
        if(5-len > s.size()-i){
            return 0;
        }
        
        if(dp[i][len][a][b] != -1){
            return dp[i][len][a][b];
        }
        
        int ans = 0;
		// First number in the palindrome
        if(len == 0){
            ans = (ans + topDown(i+1, len+1, s[i]-'0', b, s))%MOD;
        }
		// Second number in the palindrome
        else if(len == 1){
            ans = (ans + topDown(i+1, len+1, a, s[i]-'0', s))%MOD;
        }
		// Third number in the palindrome
        else if(len == 2){
            ans = (ans + topDown(i+1, len+1, a, b, s))%MOD;
        }
		// Fourth number in the palindrome
        else if(len == 3){
            if(s[i]-'0' == b){
                ans = (ans + topDown(i+1, len+1, a, b, s))%MOD;
            }
        }
		// Fifth number in the palindrome
        else if(len == 4){
            if(s[i]-'0' == a){
                ans = (ans + topDown(i+1, len+1, a, b, s))%MOD;
            }
        }
		
		// Not involving the current number
        ans = (ans + topDown(i+1, len, a, b, s))%MOD;
        return dp[i][len][a][b] = ans;
    }
    int countPalindromes(string s) {
          memset(dp, -1, sizeof(dp));
        return topDown(0, 0, 0, 0, s);
    }
};