#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int w[11][11] = {0, }; //비용 행렬
vector<bool> visited(11, false); //방문 여부
vector<int> cost; //가능한 비용들
int n, cur_cost = 0; //도시 개수, 현재 비용

// TSP 함수: 재귀적으로 모든 경로 탐색
void TSP(int from, int idx) {
  if(idx == n) { //모든 도시 방문했을 때
    if (w[from][1] != 0) { //출발지로 돌아갈 수 있다면
      cost.push_back(cur_cost + w[from][1]); //총 비용 저장
    }
    return;
  }
  
  for(int to = 2; to <= n; to++) { //다음 도시 탐색
    if (w[from][to] == 0 || visited[to] == true) { //갈 수 없거나 이미 방문한 도시면 패스
      continue;
    }
    visited[to] = true;
    cur_cost += w[from][to];
    TSP(to, idx + 1); //재귀 호출
    visited[to] = false;
    cur_cost -= w[from][to]; 
  }
  
  return;
}

int main()
{
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> w[i][j];
    }
  }
  
  visited[1] = true; //출발지 방문 처리
  TSP(1, 1); //TSP 함수 호출
  
  int min_cost = 100000000;
  for (int i = 0; i < cost.size(); i++) { //cost 벡터를 순회하며 최소 비용 갱신
    min_cost = min(cost[i], min_cost); 
  }
  
  cout << min_cost;
  
  return 0;
}