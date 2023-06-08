class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1) return {0};
        vector<int> ans;
        if(n%2)
        {
            int val=1;
        for(int i=0;i<n/2;i++)
        {
            ans.push_back(val);
            ans.push_back(-val);
            val++;
        }
            ans.push_back(0);
        }
        else
        {
           int val=1;
        for(int i=0;i<n/2;i++)
        {
            ans.push_back(val);
            ans.push_back(-val);
            val++;
        }
        }
        return ans;
    }
};