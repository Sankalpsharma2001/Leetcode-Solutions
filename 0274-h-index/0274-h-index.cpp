class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
       
        int len=citations.size();
        for(int i=0;i<citations.size();i++)
        {
            if(len-i<=citations[i])
            {
                return len-i;
            }
           
        }
        return 0;
    }
};