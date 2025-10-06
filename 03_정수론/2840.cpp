#include <iostream>
#include <vector>

using namespace std;

// 벡터의 index 위치에 알파벳을 넣을 수 있는지 확인하는 함수
bool cmp(vector<char> &v, int &index, char &alphabet) {
    if (v[index] == alphabet) { //해당 위치에 이미 같은 알파벳이 있으면
        return true; //문제 없음
    }
    if (v[index] == '?') { //해당 위치가 '?'이면
        for (char c : v) { //벡터 전체를 돌면서
            if (c == alphabet) { //이미 같은 알파벳이 있으면
                return false; //문제 있음
            }
        }
        v[index] = alphabet; //문제 없다면 해당 위치에 알파벳 넣기
        return true;
    }
    return false;
}

// 바퀴를 돌리면서 바퀴가 올바른지 확인하는 함수
bool isWheel(vector<char> &v, int &n, int &k, int &index) {
    int change;
    char alphabet;

    for (int i = 0; i < k; i++) {
        cin >> change >> alphabet;
        
        change %= n; // change가 n보다 클 수 있으므로 n으로 나눈 나머지로 변경
        index = (index + n - change) % n; // 바퀴를 시계 반대 방향으로 change만큼 돌리기
        
        if (!cmp(v, index, alphabet)) { // 해당 위치에 알파벳을 넣을 수 없으면
            return false; //바퀴가 올바르지 않음
        }
    }
    
    return true; 
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<char> v(n, '?'); // '?'로 초기화된 벡터 생성
    int index = 0;
    
    if (!isWheel(v, n, k, index)) { // 바퀴가 올바르지 않으면
        cout << "!";
        return 0;
    }
    for (int i = 0; i < n; i++) { // 바퀴 출력
        cout << v[(index + i) % n];
    }
    
    return 0;
}