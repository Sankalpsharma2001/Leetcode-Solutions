class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int ans=0;
        for(int i=1;i<=citations.size();i++)
        {
            if(i>citations[i-1])
                break;
            ans=i;
        }
        return ans;
    }
};