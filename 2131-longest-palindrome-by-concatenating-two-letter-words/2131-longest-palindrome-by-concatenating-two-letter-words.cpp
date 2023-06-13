class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count[26][26];
        memset(count,0,sizeof(count));
        int ans=0;
        for(auto &it:words)
        {
            char a=it[0],b=it[1];
            if(count[b-'a'][a-'a'])
            {
                ans+=4;
                count[b-'a'][a-'a']--;
            }
            else
            count[a-'a'][b-'a']++;
        }
        for(int i=0;i<26;i++){
				if(count[i][i]){
					ans+=2;
					break;
				}
			 }
      
	return ans;
        
        
    }
};