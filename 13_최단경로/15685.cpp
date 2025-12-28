#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool board[101][101] = {false, };

// 드래곤 커브 찾기
void findDC(int x, int y, int d, int g) {
  vector<int> dirs;
  
  board[x][y] = true; // 시작점
  
  x += dx[d];
  y += dy[d];
  board[x][y] = true; // 0세대
  dirs.push_back(d); // 방향 저장
  
  for (int gen = 1; gen <= g; gen++) { // 세대 반복
    int size = dirs.size();

    for (int i = size - 1; i >= 0; i--) { // 이전 세대 방향 역순으로
      int next_dir = (dirs[i] + 1) % 4; // 90도 회전
      x += dx[next_dir];
      y += dy[next_dir];
      board[x][y] = true;
      dirs.push_back(next_dir); // 방향 추가
    }
  }
  
  return;
}

int main()
{
  int n, count = 0;
  cin >> n;
  
  int x, y, d, g;
  
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> d >> g;
    findDC(x, y, d, g);
  }
  
  for (int i = 0; i < 100; i++) { // 1x1 사각형 개수 세기
    for (int j = 0; j < 100; j++) {
      if (board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) {
        count++;
      }
    }
  }
  
  cout << count;
  
  return 0;
}