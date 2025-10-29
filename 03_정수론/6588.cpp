#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
vector<bool> is_prime(MAX + 1, true);

// n을 두 소수의 합으로 나타낼 수 있는지 확인하는 함수
bool findSum(int n) {
  for (int a = 3; a <= n / 2; a += 2) { // a는 홀수 소수
    if (!is_prime[a]) {
      continue;
    }
    int b = n - a; // b도 홀수 소수
    if (!is_prime[b]) {
      continue;
    }
    cout << n << " = " << a << " + " << b << '\n';
    return true;
  }
  return false; // 두 소수의 합으로 나타낼 수 없음
}

// 에라토스테네스의 체로 소수 판별
void getPrime() {
  is_prime[0] = is_prime[1] = false;
  
  for (int i = 2; i * i <= MAX; i++) {
    if (!is_prime[i]) {
      continue;
    }
    for (int j = i * i; j <= MAX; j += i) {
      is_prime[j] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  // 에라토스테네스의 체로 소수 판별
  getPrime();
  int n;

  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    if (!findSum(n)) { // 두 소수의 합으로 나타낼 수 없으면
      cout << "Goldbach's conjecture is wrong.";
    }
  }
  
  return 0;
}