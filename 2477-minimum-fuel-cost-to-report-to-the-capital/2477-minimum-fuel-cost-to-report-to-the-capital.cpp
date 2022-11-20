class Solution {
public:
    long long dfs(vector<vector<int>>& graph, vector<int>& visited, long long &ans, int curr, long long &seats){
        long long ppl = 1;
        visited[curr] = 1;
        for(int i=0; i<graph[curr].size(); i++){
            if(!visited[graph[curr][i]]){
                ppl += dfs(graph, visited, ans, graph[curr][i], seats);
            }
        }
    
        if(curr!=0){
            ans += ((ppl+seats-1)/seats);
        }
        return ppl;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<vector<int>>graph(n);
        vector<int>visited(n,0);
        for(auto &i : roads){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        long long ans = 0, seat=seats;
        auto ppl = dfs(graph,visited,ans,0,seat);
        return ans;
    }
};