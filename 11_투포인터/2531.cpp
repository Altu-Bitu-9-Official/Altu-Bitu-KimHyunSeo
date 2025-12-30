#include <iostream>
#include <vector>

using namespace std;

int maxCount(vector<int> &belt, int n, int d, int k, int c) {
  int max = 0;
  
  for (int i = 0; i < n; i++) {
    vector<bool> sushi(d + 1, false); //초밥 종류별 개수 저장
    int cnt = 0;
    for (int j = i; j < i + k; j++) { //k개 초밥 선택
      if (sushi[belt[j % n]] || belt[j % n] == c) { //이미 선택된 초밥이거나 쿠폰 초밥이면 패스
        continue;
      }
      sushi[belt[j % n]] = true;
      cnt++;
    }
    if (cnt == k) { //최대치 도달 시 종료
      return k + 1; //쿠폰 초밥 추가
    }
    if (max < cnt) { //최대 개수 갱신
      max = cnt;
    }
  }
  
  return max + 1; //쿠폰 초밥 추가
}

int main()
{
  int n, d, k, c;
  cin >> n >> d >> k >> c;
  
  vector<int> belt(n);
  
  for (int i = 0; i < n; i++) {
    cin >> belt[i];
  }
  
  int result = maxCount(belt, n, d, k, c);
  cout << result;
  
  return 0;
}