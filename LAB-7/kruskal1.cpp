#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct kruskal {
  int vertex1, vertex2, edgeW;
};

bool comparison(const kruskal& a, const kruskal& b) {
  return a.edgeW < b.edgeW;
}

int findParent(int node, vector<int>& parent) {
  if (parent[node] == node) return node;
  return parent[node] = findParent(parent[node], parent);
}

int main() {
  int numVertices, numEdges, totalWeight = 0;
  cout << "Enter the number of vertices and edges in the graph: ";
  cin >> numVertices >> numEdges;
  vector<kruskal> edges(numEdges);

  cout << "Enter the vertices and edge weight of each edge: \nVertex 1\tVertex 2\tEdge Weight\n";
  for (int i = 0; i < numEdges; i++) {
    int vertex1, vertex2, edgeW;
    cin >> vertex1 >> vertex2 >> edgeW;
    if (vertex1 < 0 || vertex1 >= numVertices || vertex2 < 0 || vertex2 >= numVertices || vertex1 == vertex2 || edgeW <= 0) {
      cout << "Invalid input! Ensure vertices are between 0 and " << numVertices - 1 << ", v1 != v2, and edge weight > 0.\n";
      --i;
      continue;
    }
    edges[i].vertex1 = vertex1;
    edges[i].vertex2 = vertex2;
    edges[i].edgeW = edgeW;
  }

  sort(edges.begin(), edges.end(), comparison);
  vector<int> parent(numVertices);
  for (int i = 0; i < numVertices; i++) parent[i] = i;

  cout << "\nFinal set of vertices with edge weight in MST: \n";
  for (const auto& edge : edges) {
    int root1 = findParent(edge.vertex1, parent), root2 = findParent(edge.vertex2, parent);

    if (root1 != root2) {
      totalWeight += edge.edgeW;
      cout << edge.vertex1 << " " << edge.vertex2 << " " << edge.edgeW << endl;
      parent[root1] = root2;
    }
  }

  cout << "Total Weight: " << totalWeight << endl;

  return 0;
}