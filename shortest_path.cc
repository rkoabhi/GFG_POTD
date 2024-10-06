// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
    vector<vector<int>> adj(N);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> dist(N, INT_MAX);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbour : adj[node]) {
            if (dist[neighbour] == INT_MAX) {
                dist[neighbour] = dist[node] + 1; 
                q.push(neighbour);
            }
        }
    }

    transform(dist.begin(), dist.end(), dist.begin(), [](int d) { return d == INT_MAX ? -1 : d; });

    return dist;
    }
};
