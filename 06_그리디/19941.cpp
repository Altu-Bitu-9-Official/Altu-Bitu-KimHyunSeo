#include <iostream>
#include <string>

using namespace std;

int count(int &n, int &k, string &str) {
  int count = 0;
  
  for (int i = 0; i < n; i++) {
    if (str[i] != 'P') { // i번째 자리가 햄버거 자리라면
      continue;
    }
    // i번째 자리가 사람일 때
    for (int j = i - k; j <= i + k; j++) {
      if (j < 0 || j >= n) { // 범위 벗어나면 패스
        continue;
      }
      if (str[j] == 'H') {
        count++;
        str[j] = 'N';
        break;
      }
    }
  }
  
  return count;
}

int main()
{
  int n, k;
  string str;
  
  cin >> n >> k;
  cin >> str;

  cout << count(n, k, str);
  
  return 0;
}