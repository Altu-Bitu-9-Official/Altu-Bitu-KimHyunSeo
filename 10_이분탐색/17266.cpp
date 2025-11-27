#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(NULL);
  
  int n, m;
  cin >> n >> m;
  
  vector<int> lamp(m); // 가로등 위치 저장 벡터
  vector<int> dist(m - 1); // 가로등 사이의 거리 저장 벡터
  
  cin >> lamp[0];
  int before = lamp[0];
  for (int i = 1; i < m; i++) { // 거리 계산
    cin >> lamp[i];
    dist[i - 1] = lamp[i] - before; // 인접한 가로등 사이의 거리 저장
    before = lamp[i]; // 이전 가로등 위치 갱신
  }

  sort(dist.begin(), dist.end()); // 거리 오름차순 정렬
  
  // 출력
  int max_dist;
  if (m > 1) {
    max_dist = max((dist[m-2]+1) / 2, lamp[0]); // 가로등 사이에서 최댓값일 때 경우와 맨 앞 경우 비교
  } else {
    max_dist = lamp[0]; // 가로등이 1개일 때는 맨 앞이 최댓값
  }
  max_dist = max(max_dist, n-lamp[m-1]); // 맨 뒤 경우와 비교
  
  cout << max_dist;
  
  return 0;
}