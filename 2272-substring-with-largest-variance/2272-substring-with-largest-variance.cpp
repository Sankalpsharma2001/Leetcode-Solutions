class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        vector<int> freq(26);
        for(auto& c:s){
            freq[c-'a']++;
        }
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(ch1==ch2 or !freq[ch1-'a'] or !freq[ch2-'a']){
                    continue;
                }
                for(int rev=1;rev<=2;rev++){
                   int cnt1 = 0,cnt2 = 0;
                    for(auto& ch:s){
                        cnt1 += (ch==ch1);
                        cnt2 += (ch==ch2);
                        if(cnt1<cnt2){
                            cnt1 = cnt2 = 0;
                        }
                        if(cnt1>0 and cnt2>0){
                            ans = max(ans,cnt1-cnt2);
                        }
                    } 
                    reverse(s.begin(),s.end());
                }
 
            }
        }
        return ans;
    }
};