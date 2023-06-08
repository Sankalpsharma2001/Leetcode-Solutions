class Solution {
public:
   
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        
         sort(begin(intervals), end(intervals), [] (const auto &l, const auto &r) {
        if(l[1] != r[1]) {
            return l[1] < r[1];
        } else {
            return l[0] > r[0];   
        }
    });
    int count = 2;
    int head = intervals[0][1] - 1;
    int tail = intervals[0][1];
    for(const auto &i: intervals) {
        if(i[0] <= head) {
            continue;
        } else if(i[0] <= tail) {
            head = tail;
            tail = i[1];
            count++;
        } else {
            head = i[1] - 1;
            tail = i[1];
            count += 2;
        }
    } 
    return count;
    }
};