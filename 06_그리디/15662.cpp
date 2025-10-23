#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// 톱니바퀴 회전 함수
void rotate(deque<int> &wheel, int direction) {
  if (direction == 1) { // 시계 방향 
    int temp = wheel.back();
    wheel.pop_back();
    wheel.push_front(temp);
  } else if (direction == -1){ // 반시계 방향 
    int temp = wheel.front();
    wheel.pop_front();
    wheel.push_back(temp);
  }
}

int main()
{
  int t, k;
  cin >> t;
  deque<int> wheel[t + 1]; // 톱니바퀴를 저장할 덱 배열
  
  for (int i = 1; i < t + 1; i++) {
    string s;
    cin >> s;
    
    for (char c : s) {
      wheel[i].push_back(c - '0');
    }
  }
  
  cin >> k;
  
  for (int i = 0; i < k; i++) {
    int num, direction;
    cin >> num >> direction;
    
    vector<int> temp(t + 1, 0); // 회전 방향을 저장할 배열 (한번에 회전시키기 위해)
    temp[num] = direction;
    
    for (int j = num - 1; j > 0; j--) { // 왼쪽으로 전파
      if (wheel[j][2] == wheel[j + 1][6]) { // 맞물림이 같으면 종료
        break;
      } 
      temp[j] = -temp[j + 1]; // 이전 톱니와 반대방향
    }
    
    for (int j = num + 1; j <= t; j++) { // 오른쪽으로 전파
      if (wheel[j][6] == wheel[j - 1][2]) { // 맞물림이 같으면 종료
        break;
      }
      temp[j] = -temp[j - 1]; // 이전 톱니와 반대방향
    }
    
    for (int j = 1; j <= t; j++) { 
      if (temp[j] != 0) {
        rotate(wheel[j], temp[j]); // 회전 방향이 0이 아니면 회전
      }
    }
  }
  
  int count = 0;
  for (int i = 1; i <= t; i++) {
    if (wheel[i][0] == 1) { // 12시 방향 (인덱스 0)
      count++;
    }
  }
  
  cout << count;
  
  return 0;
}