class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int maxi=0,len=0,x=0,y=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '0'){
                x++;
            }
            else{
                y++;
            }
            len++;
  
            maxi=max(maxi,min(x,y)*2);
            if(i+1<s.length() && s[i]=='1' && s[i+1]=='0'){
                x=0;y=0;len=0;
            }
        }
        return maxi;
    }
};