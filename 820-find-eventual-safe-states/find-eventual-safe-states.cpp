
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> inDegree(n, 0);
        
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u);
                ++inDegree[u];
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for (int neighbor : reverseGraph[node]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};