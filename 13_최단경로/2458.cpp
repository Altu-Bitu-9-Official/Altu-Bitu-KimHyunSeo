#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 501;

void floydWarshall(int n, vector<vector<int>> &graph) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int cost = graph[i][k] + graph[k][j];
        graph[i][j] = min(graph[i][j], cost);
      }
    }
  }
}

int countStudent(int student, int n, vector<vector<int>> &graph) {
  int i = 1, cnt = 0;
  for (i = 1; i <= n; i++) {
    if (student != i && graph[student][i] == INF && graph[i][student] == INF) {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int n, m;
  int answer = 0;
  cin >> n >> m;
  
  vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
  
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    
    graph[a][b] = 1;
  }
  
  floydWarshall(n, graph);
  for (int i = 1; i <= n; i++) {
    answer += countStudent(i, n, graph);
  }
  
  cout << answer;
  
  return 0;
}