#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int a[1001], dp[1001]; // dp[i]: i번째 수에서 끝나는 가장 긴 증가하는 부분 수열의 길이
  int max_len = 0;

  // 가장 긴 증가하는 부분 수열(LIS) 알고리즘
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = 1;
    
    for (int j = 0; j < i; j++) { // i번째 수 이전의 수들과 비교
      if (a[i] > a[j]) { // 증가하는 부분 수열 조건 만족 시
        dp[i] = max(dp[j] + 1, dp[i]); // dp 갱신 (dp[j] + 1: j번째 수에서 끝나는 부분 수열에 i번째 수를 추가)
      }
    }
    
    if (max_len < dp[i]) { // 최장 길이 갱신
      max_len = dp[i];
    }
  }
  
  cout << max_len;
  
  return 0;
}