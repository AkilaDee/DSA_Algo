#include <iostream>
#include <vector>
#include <queue>
#include <utility>

const int INF = 1e9;

void dijkstra(int src, const std::vector<std::vector<std::pair<int, int>>>& graph, std::vector<int>& dist) {
    dist[src] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n = 5; // number of nodes
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    graph[0].emplace_back(1, 10);
    graph[0].emplace_back(3, 30);
    graph[0].emplace_back(4, 100);
    graph[1].emplace_back(2, 50);
    graph[3].emplace_back(4, 60);
    graph[4].emplace_back(2, 20);

    std::vector<int> dist(n, INF);
    dijkstra(0, graph, dist);

    std::cout << "Shortest distances from node 0: ";
    for (int d : dist)
        std::cout << d << " ";
    std::cout << std::endl;

    return 0;
}
