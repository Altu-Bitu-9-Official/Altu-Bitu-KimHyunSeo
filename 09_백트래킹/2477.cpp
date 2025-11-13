#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int k;
  cin >> k;
  
  int dir[6] = {0, }; //방향
  int len[6] = {0, }; //길이
  
  int max_row = 0, max_col = 0, small_sq = 0; //가로 최대, 세로 최대, 빼야할 작은 사각형 넓이
  
  for (int i = 0; i < 6; i++) { //입력
    cin >> dir[i] >> len[i];
  }
  
  for (int i = 0; i < 6; i++) {
    if (dir[i] == 1 || dir[i] == 2) { //가로의 최댓값 저장
      max_row = max(max_row, len[i]); 
    } else {
      max_col = max(max_col, len[i]); //세로의 최댓값 저장
    }
    
    //작은 사각형이 나오는 경우
    int now = i;
    int next = (i + 1) % 6;
    if (dir[now] == 1 && dir[next] == 3) { 
      small_sq = len[now] * len[next];
    } else if (dir[now] == 2 && dir[next] == 4) {
      small_sq = len[now] * len[next];
    } else if (dir[now] == 3 && dir[next] == 2) {
      small_sq = len[now] * len[next];
    } else if (dir[now] == 4 && dir[next] == 1) {
      small_sq = len[now] * len[next];
    }
  }
  
  int s = (max_row * max_col) - small_sq;
  cout << s * k;
  
  return 0;
}