#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이분탐색
int binarySearch(int m, int n, vector<int> &snack) {
  int left = 1, right = 1000000000;
  int max_len = 0;

  while (left <= right) {
    int mid = (left + right) / 2;
    int person = 0;
    
    for (int i = 0; i < n; i++) { // mid 길이로 잘랐을 때 몇 명에게 줄 수 있는지 계산
      person += snack[i] / mid; // mid 길이로 자른 과자의 개수
    }
    
    if (person >= m) { // 조카 수보다 많이 줄 수 있으면 길이를 늘림
      left = mid + 1;
      max_len = mid;
    } else { // 조카 수보다 적게 줄 수 있으면 길이를 줄임
      right = mid - 1;
    }
  }
  
  return max_len;
}

int main()
{
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(NULL);

  int m, n; //조카의 수, 과자의 수
  cin >> m >> n;
  
  vector<int> snack(n);
  for (int i = 0; i < n; i++) {
    cin >> snack[i];
  }
  
  sort(snack.begin(), snack.end());
  
  cout << binarySearch(m, n, snack);
  
  return 0;
}