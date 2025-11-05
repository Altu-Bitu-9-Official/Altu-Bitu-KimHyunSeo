#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int graph[MAX][MAX] = { 0, };
bool visited[MAX] = { false, };

int bfs(int &n, int &start, int &last) {
  queue<pair<int, int>> q; // first: node, second: depth
  visited[start] = true;

  q.push(make_pair(start, 0)); // 시작 노드와 깊이 0 삽입
  while(!q.empty()) {
    int now = q.front().first;
    int depth = q.front().second;
    q.pop();
    
    for(int i = 1; i <= n; i++) {
      if (graph[now][i] == 1 && !visited[i]) { // 연결되어 있고 방문하지 않은 노드라면
        if (i == last) {
          return (depth + 1); // 마지막 노드에 도달했으면 깊이 리턴
        }
        visited[i] = true;
        q.push(make_pair(i, depth + 1)); // 노드와 깊이 삽입
        
      }
    }
  }
  
  return -1;
}

int main()
{
  int n, start, last;
  int m;
  cin >> n;
  cin >> start >> last;
  cin >> m;
  
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    
    graph[x][y] = graph[y][x] = 1;
  }
  
  cout << bfs(n, start, last);
  
  return 0;
}