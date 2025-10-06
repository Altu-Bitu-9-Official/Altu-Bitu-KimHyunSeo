#include <iostream>

using namespace std;
int year = 0; // 몇 번째 해인지 저장하는 변수

// 재귀함수로 연도 구하기
void getYear(int e, int s, int m) {
  year++;
  
  while (e == 0 && s == 0 && m == 0) { // e, s, m이 모두 0이면 종료
    return;
  }
  
  // 1씩 감소시킨 뒤, 15, 28, 19의 나머지로 변환하여 재귀함수 호출
  return getYear((e-1) % 15, (s-1) % 28, (m-1) % 19);
}

int main()
{
  int e, s, m;
  cin >> e >> s >> m;
  
  //15, 28, 19의 나머지로 변환하여 재귀함수 호출
  getYear(e - 1, s - 1, m - 1);
  
  cout << year;

  return 0;
}