class Solution {
public:
    string reorganizeString(string s) {
       ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int mostFreq = 0, i = 0;
vector<int> cnt(26);
	for(char c : s)
		if(++cnt[c - 'a'] > cnt[mostFreq])
			mostFreq = (c - 'a');

	if(2 * cnt[mostFreq] - 1 > s.size()) return "";

	while(cnt[mostFreq]) {
		s[i] = ('a' + mostFreq);
		i += 2;
		cnt[mostFreq]--;
	}

	for(int j = 0; j < 26; j++) {
		while(cnt[j]) {
			if(i >= s.size()) i = 1;
			s[i] = ('a' + j);
			cnt[j]--;
			i += 2;
		}
	}

	return s;
//         unordered_map<char,int> m;// map
//      priority_queue<pair<int,char>> pq;
//         for(int i=0;i<s.length();i++)
//             m[s[i]]++;
//         for(auto it:m)
//       pq.push({it.second,it.first});
//         string ans="";
//         while(pq.size()>1)
//         {
//             auto a=pq.top();
//             pq.pop();
//             auto b=pq.top();
//             pq.pop();
//             ans+=a.second;
//             ans+=b.second;
//             a.first-=1;
//             b.first-=1;
//             if(a.first>0)
//                 pq.push(a);
//             if(b.first>0)
//                 pq.push(b);
            
//         }
//         if(!pq.empty())
//         {
//             if(pq.top().first>1)
//                 return "";
//             else 
//                 ans+=pq.top().second;
            
//             pq.pop();
//         }
//         return ans;
    }
    
};