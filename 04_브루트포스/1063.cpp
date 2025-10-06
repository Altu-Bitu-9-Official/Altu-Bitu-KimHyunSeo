#include <iostream>
#include <string>

using namespace std;

// 방향을 구하는 함수
pair<int, int> getDirection(string &shift) {
    int row = 0; // 열 초기화
    int column = 0; // 행 초기화
    
    switch (shift[0]) { // 첫 번째 문자에 따라 방향 설정
        case 'R':
            row++;
            break;
        case 'L':
            row--;
            break;
        case 'T':
            column++;
            break;
        case 'B':
            column--;
            break;
    }
    
    if (shift[1] == '\n') { // 두 번째 문자가 없으면 첫 번째 문자에 따른 방향 반환
        return make_pair(row, column);
    }
    
    switch (shift[1]) { // 두 번째 문자에 따라 방향 설정
        case 'T':
            column++;
            break;
        case 'B':
            column--;
            break;
    }
    return make_pair(row, column);
}

// 킹과 돌을 움직이는 함수
void moveKingAndStone(string &king, string &stone, string &shift) {
    string temp_kn = king; // 임시 킹 위치
    string temp_st = stone; // 임시 돌 위치
    
    // 이동 방향 구하기
    pair<int, int> direction = getDirection(shift);

    // 킹 이동
    temp_kn[0] += direction.first;
    temp_kn[1] += direction.second;

    // 킹이 체스판을 벗어나면 이동하지 않음
    if (temp_kn[0] < 'A' || temp_kn[0] > 'H' || temp_kn[1] < '1' || temp_kn[1] > '8') {
        return;
    }
    
    // 킹이 돌과 같은 위치에 있으면 돌 이동
    if (temp_kn == temp_st) {
        temp_st[0] += direction.first;
        temp_st[1] += direction.second;
        // 돌이 체스판을 벗어나면 이동하지 않음
        if (temp_st[0] < 'A' || temp_st[0] > 'H' || temp_st[1] < '1' || temp_st[1] > '8') {
            return;
        }
    }

    // 이동이 유효하면 위치 업데이트
    king = temp_kn;
    stone = temp_st;
    
}

int main()
{

    string king, stone;
    int n;
    string shift;
    
    cin >> king >> stone >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> shift; // 이동 명령 입력
        moveKingAndStone(king, stone, shift); // 킹과 돌 이동
    }
    
    cout << king << '\n';
    cout << stone << '\n';

    return 0;
}