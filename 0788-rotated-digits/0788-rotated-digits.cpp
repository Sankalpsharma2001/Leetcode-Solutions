class Solution {
public:
    set<int> st;
     bool isValid(int N)
    {
       bool validFound = false;
        while (N > 0) {
            if (N % 10 == 2) validFound = true;
            if (N % 10 == 5) validFound = true;
            if (N % 10 == 6) validFound = true;
            if (N % 10 == 9) validFound = true;
            if (N % 10 == 3) return false;
            if (N % 10 == 4) return false;
            if (N % 10 == 7) return false;
            N = N / 10;
        }
        return validFound;
    }
    int rotatedDigits(int n) {
         st.insert(2);
          st.insert(5);
          st.insert(6);
          st.insert(9);
        int count = 0;
        for (int i = 1; i <= n; i ++) {
            if (isValid(i)) count ++;
        }
        return count;
    }
};