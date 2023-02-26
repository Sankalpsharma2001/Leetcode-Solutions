class Solution {
public:
   static bool com(vector<int> &a,vector<int> &b)
   {
       return a[1]<b[1];
   }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),com);
        priority_queue<int> pq;
        int x=0;
        for(int i=0;i<courses.size();i++)
        {
            x+=courses[i][0];
            pq.push(courses[i][0]);
            if(x>courses[i][1])
            {
                x-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};