#include<bits/stdc++.h>
using namespace std;
void dfs(int start, vector<int> adj[], vector<bool>& visited) {
    visited[start] = true;
    for (auto u : adj[start]) {
        if (!visited[u]) {
            dfs(u, adj, visited);
        }
    }
}

void findVertices(int start, int end, vector<int> adj[], vector<bool>& visited, vector<bool>& visited2, vector<int>& vertices) {
    visited[start] = true;
    for (auto u : adj[start]) {
        if (!visited[u] && !visited2[u]) {
            vertices.push_back(u);  // Node u is reachable from start but not from end, so it needs to be removed
        }
        if (!visited[u]) {
            findVertices(u, end, adj, visited, visited2, vertices);
        }
    }
}

vector<int> removeVertices(int start, int end, vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    dfs(start, adj, visited);  // Find all reachable nodes from the start node

    vector<bool> visited2(n, false);
    dfs(end, adj, visited2);   // Find all reachable nodes from the end node

    vector<int> vertices;
    vector<bool> visited3(n, false);
    findVertices(start, end, adj, visited, visited2, vertices);  // Find the nodes that need to be removed

    return vertices;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int start, end;
    cin >> start >> end;

    vector<int> ans = removeVertices(start, end, adj, n);
    cout << ans.size();
    cout << "Vertices to remove: ";
    for (auto v : ans) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
