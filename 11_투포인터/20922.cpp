#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_RANGE 100000

using namespace std;

// 최장 길이를 구하는 함수
int maxLength(vector<int> &arr, int n, int k) {
  int result = 0;
  int right = 1, left = 1;
  vector<int> same(MAX_RANGE + 1, 0); // 각 숫자의 등장 횟수 저장
  
  while (right <= n) { // right가 배열의 끝에 도달할 때까지
    same[arr[right]]++; // right 위치의 숫자 횟수 추가
    if (same[arr[right]] <= k) { // k 이하인 경우 최장 길이 갱신
      result = max(result, right - left + 1);
      right++; // right 포인터 이동
      continue;
    }
    
    while (same[arr[right]] > k) { // k 초과 시 left 포인터 이동
      same[arr[left]]--; // left 위치의 숫자 횟수 감소
      left++;
    }
    right++; // right 포인터 이동
  }
  
  return result;
}

int main()
{
  int n, k;
  cin >> n >> k;
  
  vector<int> arr(n + 1);
  
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  
  int result = maxLength(arr, n, k);
  cout << result;
  
  return 0;
}