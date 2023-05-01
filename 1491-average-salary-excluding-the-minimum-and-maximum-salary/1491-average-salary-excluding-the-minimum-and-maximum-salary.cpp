class Solution {
public:
    double average(vector<int>& salary) {
        int s=accumulate(salary.begin(),salary.end(),0ll);
        int mn=*min_element(salary.begin(),salary.end());
        int mx=*max_element(salary.begin(),salary.end());
        s-=(mn+mx);
        int n=salary.size();
        n-=2;
        return double(s)/n*1.0;
    }
};