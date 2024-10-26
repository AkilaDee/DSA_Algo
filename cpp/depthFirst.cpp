#include <iostream>
#include <vector>

void dfs(int v, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited) {
    visited[v] = true;
    std::cout << v << " ";

    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u, graph, visited);
        }
    }
}

int main() {
    int n = 5; // number of nodes
    std::vector<std::vector<int>> graph(n);
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2};

    std::vector<bool> visited(n, false);

    std::cout << "DFS starting from node 0: ";
    dfs(0, graph, visited);
    std::cout << std::endl;

    return 0;
}
