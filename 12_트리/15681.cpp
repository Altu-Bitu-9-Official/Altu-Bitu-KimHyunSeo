#include <iostream>
#define MAXN 100001
using namespace std;

int subSize[MAXN];
int head[MAXN];
int to[2 * MAXN];
int nxt[2 * MAXN];
int ecnt = 0;

// 그래프에 간선 추가
void addEdge(int u, int v) {
    to[ecnt] = v;
    nxt[ecnt] = head[u];
    head[u] = ecnt++;
}

// DFS로 서브트리 크기 계산
int dfs(int cur, int parent) {
    subSize[cur] = 1;
    
    for (int i = head[cur]; i != -1; i = nxt[i]) { // 인접한 모든 정점 탐색
        int next = to[i];
        if (next == parent) { // 부모 노드라면 무시
          continue;
        }
        subSize[cur] += dfs(next, cur); // 서브트리 크기 누적
    }
    
    return subSize[cur];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, r, q;
    cin >> n >> r >> q;

    for (int i = 1; i <= n; i++)
        head[i] = -1;

    for (int i = 0; i < n - 1; i++) { // 간선 정보 입력
        int u, v;
        cin >> u >> v;
        addEdge(u, v); // 무방향 그래프이므로 양쪽에 간선 추가
        addEdge(v, u);
    }

    dfs(r, 0);

    while (q--) {
        int u;
        cin >> u;
        cout << subSize[u] << '\n';
    }
    return 0;
}