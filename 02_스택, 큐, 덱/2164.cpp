#include <iostream>
#include <queue>

using namespace std;

//큐에 1부터 n까지의 수를 넣는 함수
queue<int> setQueue(int& n) {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }
    return q;
}

int main() {
    int n;
    int temp;
    
    cin >> n;
    
    //큐 초기화
    queue<int> q = setQueue(n);
    
    //큐에 원소가 1개 남을 때까지 순회
    while (q.size() > 1) {
        q.pop(); //맨 앞의 원소를 빼고
        temp = q.front(); //맨 앞의 원소를 빼서
        q.pop(); //삭제한 뒤
        q.push(temp); //맨 뒤에 다시 넣음
    }
    
    cout << q.front() << '\n';

    return 0;
}