class Solution {
public:
    bool no_Zero(int n) {
        while (n>0)
        {
            if (n % 10 == 0)
                return false;
            n /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++)
        {
            int a=i,b=n-i;
            if(no_Zero(a) and no_Zero(b))
                return {a,b};
        }
        return {};
    }
};