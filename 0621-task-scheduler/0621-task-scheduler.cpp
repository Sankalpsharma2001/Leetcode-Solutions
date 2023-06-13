class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      unordered_map<int,int> m;
        for(auto &it:tasks)
        {
            m[it]++;
        }
        priority_queue<int> pq;
        for(auto &it:m)
        {
            pq.push(it.second);
        }
        int cycle=n+1;
        int alltime=0;
        
        while(!pq.empty())
        {
            int time=0;
            vector<int> tmp;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (int cnt : tmp) {
                if (--cnt) {
                    pq.push(cnt);
                }
            }
            alltime += !pq.empty() ? cycle : time;
            
        }
     return alltime;
    }
};