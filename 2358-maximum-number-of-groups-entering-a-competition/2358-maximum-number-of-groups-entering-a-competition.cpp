class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
       int n=grades.size();
        int i=1,sum=0;
        while(sum+i<=n)
        {
            sum+=i;
            i++;
        }
        return i-1;
    }
};