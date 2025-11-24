#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[20][20] = {0, };
pair<int, int> location = make_pair(0, 0);
int winner = 0;
vector<int> dx = {1, 1, 0 ,-1};
vector<int> dy = {0, 1, 1, 1};

// 돌일 때 오목인지 확인하는 함수
bool checkFive(int &i, int &j) {
  int x, y;

  for (int a = 0; a < 4; a++) { // 4방향 탐색
    x = dx[a];
    y = dy[a];
    int cnt = 1;
    if ((i + x) < 0 || (i + x) > 19 || (j + y) < 0 || (j + y) > 19) { // 범위 벗어나면 패스
      continue;
    }
    if (board[i - x][j - y] == board[i][j]) { // 반대 방향에 같은 돌이 있으면 패스 (이미 체크한 방향)
      continue;
    }
    if (board[i + x][j + y] != board[i][j]) { // 바로 다음 칸이 다른 돌이면 패스
      continue;
    }
    cnt++; // 다음 칸이 같은 돌이면 카운트 증가
    while (true) { // 계속 같은 돌이 있는지 확인
      x += dx[a];
      y += dy[a];
      if (board[i + x][j + y] != board[i][j]) { // 다른 돌이 나오면 종료
        break;
      }
      cnt++;
    }
    if (cnt == 5) { // 오목이면 위치와 승자 저장 후 true 리턴
      location = make_pair(i, j);
      winner = board[i][j];
      return true;
    }
  }
  return false;
}

// 전체 보드를 탐색하는 함수
void game() {
  int x, y;
  
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j < 20; j++) {
        if (board[i][j] == 0) { // 빈 칸이면 패스
          continue;
        }
        if (checkFive(i, j)) { // 오목이면 종료
          return;
        }
    }
  }
}

int main()
{
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j < 20; j++) {
      cin >> board[i][j];
    }
  }
  
  game(); // 탐색 시작
  
  cout << winner << '\n';
  if (winner != 0) {
    cout << location.first << ' ' << location.second;
  }
  
  return 0;
}