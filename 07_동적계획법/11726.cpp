#include <iostream>
#include <vector>
#define MOD 10007

using namespace std;

// 타일 개수를 세는 함수
int countRect(int &n) {
  vector<int> cnt(n + 1, 0);
  cnt[1] = 1;
  cnt[2] = 2;
  
  for (int i = 2; i < n; i++) { // 점화식 적용
    cnt[i + 1] = (cnt[i] + cnt[i - 1]) % MOD; // 범위를 벗어나지 않도록 MOD 연산 결과로 저장
  }
  
  return cnt[n];
}
int main()
{
  int n;
  cin >> n;
  
  int result = countRect(n);
  cout << result;
  
  return 0;
}