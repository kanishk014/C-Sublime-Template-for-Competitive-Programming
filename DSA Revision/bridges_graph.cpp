class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<int> &time, vector<int> &lowestTime, vector<bool> &visited, int source, int parent, int t, vector<vector<int>> &ans) {
        visited[source] = true;
        time[source] = t;
        lowestTime[source] = t;

        for (auto v: graph[source]) {
            if (visited[v] == true and v != parent) {
                lowestTime[source] = min(lowestTime[v], lowestTime[source]);                
            }
            else if (visited[v] == false) {
                dfs(graph, time, lowestTime, visited, v, source, t + 1, ans);
                lowestTime[source] = min(lowestTime[v], lowestTime[source]);
                if (lowestTime[v] > time[source]) {
                    vector<int> temp = {source, v};
                    ans.push_back(temp);
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<int> time(n), lowestTime(n, INT_MAX);
        vector<bool> visited(n, false);
        vector<vector<int>> ans;

        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }                        
        dfs(graph, time, lowestTime, visited, 0, -1, 1, ans);

        return ans;
    }
};
