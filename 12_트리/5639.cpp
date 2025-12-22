#include <iostream>
#define MAXN 10000

using namespace std;

int pre[MAXN];
int n = 0;

void postOrder(int l, int r) {
  if (l >= r) { // 끝 조건
    return;
  }

  int root = pre[l];
  int idx = l + 1;

  // 오른쪽 서브트리 시작점 찾기
  while (idx < r && pre[idx] < root) idx++;

  postOrder(l + 1, idx); // 왼쪽 서브트리
  postOrder(idx, r); // 오른쪽 서브트리
  cout << root << '\n'; // 루트 출력
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> pre[n]) {
    n++;
  }

  postOrder(0, n);
  return 0;
}