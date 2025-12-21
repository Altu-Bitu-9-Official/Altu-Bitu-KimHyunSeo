#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int board[MAX][MAX] = {0, };
pair<int, char> pi[MAX];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

// 시뮬레이션 함수
int playDummy(int n) {
  int dir = 0, sec = 0, x = 1, y = 1, index = 0;
  queue<pair<int, int>> snake;
  
  snake.push(make_pair(x, y)); // 뱀의 처음 위치
  board[x][y] = -1;
  
  while(true) {
    // 1. 뱀 이동
    x += dx[dir]; 
    y += dy[dir];
    sec++;
    
    // 2. 벽 또는 자기자신과 부딪혔는지 확인
    if (x < 1 || x > n || y < 1 || y > n) {
      return sec;
    }
    if (board[x][y] == -1) {
      return sec;
    } 
    
    // 3. 사과가 있는지 확인
    if (board[x][y] == 1) {
      board[x][y] = 0;
    } else { // 사과가 없으면 꼬리 제거
      int back_x, back_y;
      back_x = snake.front().first;
      back_y = snake.front().second;
      board[back_x][back_y] = 0;
      snake.pop();
    }
    
    board[x][y] = -1;
    snake.push(make_pair(x, y));
    
    // 4. 방향 전환이 있는지 확인
    if (pi[index].first == sec) {
      if (pi[index].second == 'D') {
        dir = (dir + 1) % 4;
      } else {
        dir = (dir + 3) % 4;
      }
      index++;
    }
    
  }
  
  return sec;
}

int main()
{
  int n, k, l;
  cin >> n >> k;
  
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    
    board[x][y] = 1;
  }
  
  cin >> l;
  
  for (int i = 0; i < l; i++) {
    int x;
    char c;
    cin >> x >> c;
    
    pi[i] = make_pair(x, c);
  }
  
  int result = playDummy(n);
  cout << result;
  
  return 0;
}