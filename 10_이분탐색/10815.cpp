#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이분 탐색 함수
int binarySearch(int n, int key, vector<int> & card) {
  int left = 0, right = n - 1;
  
  while (left <= right) { // 탐색 범위가 남아있는 동안
    int mid = (left + right) / 2;
    if (card[mid] == key) { // 값을 찾은 경우
      return 1;
    }
    if (key < card[mid]) { // 중간 값보다 작은 경우 왼쪽 탐색
      right = mid - 1;
    } else { // 중간 값보다 큰 경우 오른쪽 탐색
      left = mid + 1;
    }
  }
  return 0;
}

int main()
{
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(NULL);
  
  int n, m, key;
  
  cin >> n;
  vector<int> card(n);
  for (int i = 0; i < n; i++) {
    cin >> card[i];
  }
  
  sort(card.begin(), card.end()); // 이분 탐색을 위해 정렬
  
  cin >> m;
  while (m--) {
    cin >> key;
    cout << binarySearch(n, key, card) << ' ';
  }
  
  return 0;
}