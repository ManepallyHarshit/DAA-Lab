#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct Edge {
  int u, v, weight;
  bool operator<(const Edge& other) const {
    return weight < other.weight;
  }
};

int find(int i, vector<int>& parent) {
  if (parent[i] == i)
    return i;
  return parent[i] = find(parent[i], parent);
}

bool unite(int u, int v, vector<int>& parent, vector<int>& rank) {
  int root_u = find(u, parent);
  int root_v = find(v, parent);
  if (root_u != root_v) {
    if (rank[root_u] < rank[root_v])
      swap(root_u, root_v);
    parent[root_v] = root_u;
    if (rank[root_u] == rank[root_v])
      rank[root_u]++;
    return true;
  }
  return false;
}

int main() {
  int n, m, mst_weight = 0;
  cout << "Enter number of vertices and edges: ";
  cin >> n >> m;

  vector<Edge> edges(m), mst;
  cout << "Enter edges (u v weight) 0-indexed:\n";
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].u >> edges[i].v >> edges[i].weight;
  }
  sort(edges.begin(), edges.end());

  vector<int> parent(n);
  iota(parent.begin(), parent.end(), 0);
  vector<int> rank(n, 0);

  for (const auto& edge : edges) {
    if (unite(edge.u, edge.v, parent, rank)) {
      mst_weight += edge.weight;
      mst.push_back(edge);
      if (mst.size() == static_cast<size_t>(n - 1))
        break;
    }
  }

  if (mst.size() == static_cast<size_t>(n - 1) || n == 1) {
    cout << "\nMinimum Spanning Tree Edges:\n";
    for (const auto& edge : mst) {
      cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }
    cout << "Total Weight: " << mst_weight << "\n";
  } else {
    cout << "\nGraph is disconnected. No MST exists.\n";
  }

  return 0;
}