#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num(12, 0);
vector<int> op(4, 0); // 0:+  1:-  2:*  3:/
vector<int> result;
int n = 0;

// 연산자에 따라 계산하는 함수
long long calculation(int &tmp, int &x, int &i) {
  long long next; // 다음 계산 결과
  
  switch(i) { // i에 따라 연산자 선택
    case 0:
      next = tmp + x;
      return next;
    case 1:
      next = tmp - x;
      return next;
    case 2:
      next = tmp * x;
      return next;
    case 3:
      next = tmp / x;
      return next;
  }
  
}

// 백트래킹 함수
void backtracking(int tmp, int idx) { // idx: 계산할 다음 수의 번째
  if (idx == (n + 1)) { // 모든 수를 다 계산했으면 결과 저장 후 종료
    result.push_back(tmp);
    return;
  }
  
  for (int i = 0; i < op.size(); i++) { // 4가지 연산자 탐색
    if (op[i] == 0) { // 현재 i의 연산자가 남아있지 않다면
      continue;
    }
    long long next = calculation(tmp, num[idx], i); // 반대로, 남아있다면 i의 값에 따라 연산자 선택해서 계산
    if (next > 1000000000 || next < -1000000000) { // 계산 결과가 범위 벗어나면 패스
      continue;
    }
    op[i]--; // 사용한 연산자 개수 하나 감소
    backtracking(next, idx + 1); // 재귀 호출
    op[i]++; // 연산자 개수 되돌리기
  }
}

int main()
{
  // 입력
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  for (int i = 0; i < op.size(); i++) {
    cin >> op[i];
  }
  
  // 연산
  backtracking(num[1], 2);
  
  int largest = -1000000001, smallest = 1000000001; // 결과의 최댓값, 최솟값 초기화
  for (int i = 0; i < result.size(); i++) {
    largest = max(largest, result[i]);
    smallest = min(smallest, result[i]);
  }

  // 출력
  cout << largest << '\n' << smallest;
  
  return 0;
}