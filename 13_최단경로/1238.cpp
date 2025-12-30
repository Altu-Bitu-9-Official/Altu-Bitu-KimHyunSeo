#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int N, M, X;

// 다익스트라 함수
vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start}); // {비용, 현재 노드}

    while (!pq.empty()) {
        int d = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < d) continue;

        for (auto& edge : graph[now]) {
            int next_node = edge.first;
            int weight = edge.second;
            int cost = d + weight;

            if (cost < dist[next_node]) {
                dist[next_node] = cost;
                pq.push({cost, next_node});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<vector<pair<int, int>>> reverse_graph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        reverse_graph[v].push_back({u, w}); // 간선 뒤집기
    }

    // X에서 각 집으로 돌아오는 최단 거리
    vector<int> dist_back = dijkstra(X, graph);

    // 각 집에서 X로 가는 최단 거리 (역방향 그래프 활용)
    vector<int> dist_to = dijkstra(X, reverse_graph);

    int max_time = 0;
    for (int i = 1; i <= N; i++) {
        if (dist_to[i] != INF && dist_back[i] != INF) {
            max_time = max(max_time, dist_to[i] + dist_back[i]);
        }
    }

    cout << max_time << "\n";

    return 0;
}