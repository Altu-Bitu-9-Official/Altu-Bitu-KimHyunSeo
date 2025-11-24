#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

int graph[MAX][MAX] = {0, };
vector<bool> visited(MAX, 0);
queue<int> q;

// BFS를 이용하여 1번 컴퓨터와 연결된 컴퓨터의 수를 세는 함수
int result(int &n) {
  int cnt = 0;
  
  q.push(1);
  visited[1] = true;
  
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    
    for (int i = 1; i <= n; i++) {
      if (graph[top][i] == 1 && !visited[i]) {
        visited[i] = true;
        q.push(i);
        cnt++;
      }
    }
  }
  
  return cnt;
}

int main()
{
  int n, m;
  cin >> n >> m;
  
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = graph[y][x] = 1;
  }
  
  cout << result(n);
  
  return 0;
}