#include <iostream>
#include <stack>

using namespace std;

// 최소 속도를 구하는 함수
long long minSpeed(int &n, stack<int> &v) {
  long long min = 0;
  
  // 스택이 빌 때까지 반복
  while (!v.empty()) {
    int top = v.top();
    v.pop();
    
    if (top > min) { // 현재 최소 속도보다 크면 갱신
      min = top;
    } else if (min % top == 0) { // 나누어 떨어지면 패스
      continue;
    } else { // 나누어 떨어지지 않으면 최소 속도 갱신
      long long mult = min / top + 1;
      min = top * mult;
    }
  }
  
  return min;
}

int main()
{
  int n;
  cin >> n;

  stack<int> v; // 스택을 이용해서 뒷 부분부터 처리
  for (int i = 0; i < n; i++) {
    int speed;
    cin >> speed;
    v.push(speed);
  }
  
  cout << minSpeed(n, v);

  return 0;
}