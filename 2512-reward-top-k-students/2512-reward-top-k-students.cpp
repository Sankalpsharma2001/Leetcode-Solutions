class Solution {
public:
    class Compare {
public:
    bool operator()(pair<int,int> &below, pair<int,int> &above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }
 
        return false;
    }
};
 
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
       set<string> pos(positive_feedback.begin(),positive_feedback.end());
       set<string> neg(negative_feedback.begin(),negative_feedback.end()); 
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        for(int i=0;i<student_id.size();i++)
        {
            string s=report[i];
            int point=0;
            for(int i=0;i<s.size();i++)
            {
                string str="";
                while(i<s.size() && s[i]!=' ')
                {
                    str+=s[i++];
                    
                }
                if(pos.find(str)!=pos.end())
                {
                    point+=3;
                }
                if(neg.find(str)!=neg.end())
                {
                    point-=1;
                }
            }
            // cout<<point<<endl;
            pq.push({point,student_id[i]});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};