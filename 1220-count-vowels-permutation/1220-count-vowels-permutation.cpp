class Solution {
public:
     const int MOD = 1e9 + 7;
const unordered_map<char, vector<char>> mappings{ {'s', {'a', 'e', 'i', 'o', 'u'} }, // start
                                                      {'a', {'e'}                     }, 
                                                      {'e', {'a', 'i'}                }, 
                                                      {'i', {'a', 'e', 'o', 'u'}      }, 
                                                      {'o', {'i', 'u'}                },
                                                      {'u', {'a'}                     }  };
    unordered_map<char, vector<int>> dp;
    int countVowelPermutation(int n) {
        
       // dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n+1);
       //  return solve(n, 's');     
       //   const int MOD = 1e9 + 7;
        long a = 1, e = 1, i = 1, o = 1, u = 1, a_new, e_new, i_new, o_new, u_new;
        for(int j = 2; j <= n; j++) {
            a_new =  e;
            e_new = (a + i) % MOD;
            i_new = (a + e + o + u) % MOD;
            o_new = (i + u) % MOD;
            u_new =  a;
            a = a_new, e = e_new, i = i_new, o = o_new, u = u_new;
        }
        return (a + e + i + o + u) % MOD;
    }
    long long solve(int rem, char prev) {
        if(rem == 0) return 1;                        // no need to pick further. We have formed 1 string of length = n.
        if(dp[prev][rem]) return dp[prev][rem];       // if result already calculated for current state, directly return it
        long long ans=0;
        for(auto &c : mappings.at(prev))               // try each vowel allowed after prev character
           ans = (ans + solve(rem - 1, c)) % MOD;  
        return dp[prev][rem]=ans%MOD;
        
        
    }
};