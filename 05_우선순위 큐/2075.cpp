#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    // 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;

    int idx;
    for (int i = 0; i < n; i++) { // 처음 n개는 무조건 삽입
        cin >> idx;
        pq.push(idx);
    }

    for (int i = n; i < n * n; i++) { // 그 이후부터는 최소힙의 최솟값과 비교
        cin >> idx;
        if (idx > pq.top()) { // 새로 들어온 값이 최소힙의 최솟값보다 크면
            pq.pop(); // 최소힙의 최솟값 제거
            pq.push(idx); // 새로 들어온 값 삽입
        }
    }
    cout << pq.top();

    return 0;
}