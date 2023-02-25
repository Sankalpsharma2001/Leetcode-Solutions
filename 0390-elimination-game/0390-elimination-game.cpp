class Solution {
public:
    int lastRemaining(int n) {
        // bool left=true;
        // int head=1,step=1,remain=n;
        // while(remain>1)
        // {
        //     if(left || remain&1)
        //     {
        //         head=head+step;
        //     }
        //     step*=2;
        //     left=!left;
        //     remain/=2;
        // }
        // return head;
        return recursion(n, true);
    }
     int recursion(int n, bool isLeft) {
        if(n == 1) return n;
        if(!isLeft && (n % 2) == 0) {
            // eliminate all the even numbers
            // [1, 2, 3, 4, 5, 6] -> [1, 3, 5]
            // It is equivalent to consider the number left in [1, 2, 3] * 2 - 1
            return recursion(n / 2, !isLeft) * 2 - 1;
        } else {
            // eliminate all the odd numbers
            // [1, 2, 3, 4, 5, 6] -> [2, 4, 6]
            // It is equivalent to consider the number left in [1, 2, 3] * 2
            return recursion(n / 2, !isLeft) * 2;
        }
    }
};