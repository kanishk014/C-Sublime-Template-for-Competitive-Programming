/*
Things to keep in mind that are different than bridges in a graph:

1. Check for the starting node, if it has more than 1 child which are not visited then it will be an articulation point
2. Condition for checking articulation point: (low[v] >= time[u] and parent != -1)
3. Do not take low values of the visited nodes v, rather take their curr time values for updating low of u (Because, had we taken low values of visited nodes v,
then it may happen that the path is going via v and we do not want that because v could be removed).
*/


class Solution {
  public:
    set<int> ans;
    int time = 0;
    
    void dfs(vector<int> adj[], int u, vector<bool> &visited, vector<int> &low, vector<int> &currTime, int par) {
        visited[u] = true;
        
        currTime[u] = time;
        low[u] = time;
        
        time++;
        
        int child = 0;
        for (auto v: adj[u]) {
            if (v == par) continue;
            if (visited[v] == false) {
                dfs(adj, v, visited, low, currTime, u);
                low[u] = min(low[u], low[v]);

                // Condition for checking if a node v can reach before u
                if (low[v] >= currTime[u] and par != -1) {
                    ans.insert(u);
                }
                
                child++;
            }
            else {
                // Not taking low[v] values of visited nodes, rather take their currTime[v].
                low[u] = min(low[u], currTime[v]);
            }
        }

      // Check for whether starting node has more than 1 child that are unvisited.
        if (child > 1 and par == -1) {
            ans.insert(u);
        }
    }
    
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> low(n);
        vector<int> currTime(n);
        
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(adj, i, visited, low, currTime, -1);
            }
        }
        
        vector<int> v;
        
        for (auto e: ans) v.push_back(e);
            
        if (v.size() == 0) {
            return {-1};
        }
        
        return v;
    }
};
