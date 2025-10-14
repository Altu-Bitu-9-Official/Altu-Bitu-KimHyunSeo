#include <iostream>
#include <vector>

using namespace std;

// base와 s가 비슷한 단어인지 확인하는 함수
bool cmp(string &base, string &s, vector<int> &base_v, vector<int> &v) {
  int diff = 0; // 각 알파벳 개수 차이의 합
  
  for (int k = 0; k < 26; k++) {
    diff += abs(base_v[k] - v[k]);
  }
  
  int len_diff = abs((int)base.size() - (int)s.size()); // 길이 차이

  if (diff == 0) { // 같음
    return true;
  } else if (len_diff == 0 && diff == 2) { // 길이 같고, 알파벳 개수 차이의 합이 2 -> 하나만 바꿈
    return true;
  } else if (len_diff == 1 && diff == 1) { // 길이 차이 1, 알파벳 개수 차이의 합이 1 -> 하나만 추가/삭제
    return true;
  } 
  return false; // 그 외는 다름
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  string base;
  vector<int> base_v(26, 0);
  
  cin >> n;
  cin >> base;

  for (char c : base) {
    base_v[c - 'A']++; // base 단어의 알파벳 개수를 벡터에 저장
  }

  int answer = 0;
  for (int i = 0; i < n-1; i++) {
    string s;
    vector<int> v(26, 0);
    
    cin >> s;
    for (char c : s) { 
      v[c - 'A']++; // s 단어의 알파벳 개수를 벡터에 저장
    }
    
    answer += cmp(base, s, base_v, v); // 비슷한 단어인지 확인 후, 맞으면 1 더하기
  }
  
  cout << answer;
  
  return 0;
}