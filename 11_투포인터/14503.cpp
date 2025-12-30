#include <iostream>
#define SIZE 50

using namespace std;

int n = 0, m = 0;
int space[SIZE][SIZE];

int count = 0;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

//로봇 청소기 작동 함수
void countCleaning(int r, int c, int d) {

  if (space[r][c] != -1) { //청소되지 않은 공간일 경우
    count++;
    space[r][c] = -1; //청소 완료 처리
  }
  
  for (int i = 0; i < 4; i++) {  //반시계 방향으로 탐색
    int new_d = (d - i + 3) % 4;
    
    if (space[r+dy[new_d]][c+dx[new_d]] == 0) { //청소되지 않은 공간 발견 시
      countCleaning(r+dy[new_d], c+dx[new_d], new_d); // 그 방향으로 이동
      return; 
    }
  }
  
  int back_d = (d + 2) % 4; //후진 방향 계산
  
  if (space[r+dy[back_d]][c+dx[back_d]] == 1) { //후진 방향이 벽일 경우 작동 종료
    return;
  }
  
  countCleaning(r+dy[back_d], c+dx[back_d], d); //후진 이동
  return;
}

int main()
{
  int r, c, d;
  cin >> n >> m;
  cin >> r >> c >> d;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> space[i][j];
    }
  }

  countCleaning(r, c, d);
  cout << count;
  
  return 0;
}