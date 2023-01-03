class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int cnt=0;
        for(int i=0;i<strs[0].size();i++)
        {
            char pre=strs[0][i];
        for(int j=1;j<n;j++)
        {
            if(pre>strs[j][i])
            {
                cnt++;
                break;
            }
            pre=strs[j][i];
        }
            
        }
        return cnt;
    }
};