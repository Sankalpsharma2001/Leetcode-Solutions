class Solution {
public:
    int minFlips(string target) {
        int ans=0;
        if(target[0]=='1') ans++;
        for(int i=0;i<target.size()-1;i++)
        {
            if(target[i]!=target[i+1])
                ans++;
        }
        return ans;
    }
};