#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int primMST(int V, const vector<vector<pair<int, int>>>& adj) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> key(V, INT_MAX);
  vector<int> parent(V, -1);
  vector<bool> inMST(V, false);

  pq.push({0, 0});
  key[0] = 0;
  int total_weight = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    int weight = pq.top().first;
    pq.pop();

    if (inMST[u]) continue;

    inMST[u] = true;
    total_weight += weight;

    for (const auto& edge : adj[u]) {
      int v = edge.first;
      int w = edge.second;

      if (!inMST[v] && w < key[v]) {
        key[v] = w;
        parent[v] = u;
        pq.push({key[v], v});
      }
    }
  }

  cout << "\nEdges in MST:\n";
  for (int i = 1; i < V; ++i) {
    if (parent[i] != -1) cout << parent[i] << " - " << i << " : " << key[i] << "\n";
  }

  return total_weight;
}

int main() {
  int V, E;
  cout << "Enter number of vertices and edges: ";
  cin >> V >> E;

  vector<vector<pair<int, int>>> adj(V);

  cout << "Enter edges (u v weight):\n";
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int total_weight = primMST(V, adj);
  cout << "Total MST Weight: " << total_weight << endl;

  return 0;
}