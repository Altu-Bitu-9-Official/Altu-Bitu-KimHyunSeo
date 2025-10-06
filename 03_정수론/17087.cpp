#include <iostream>
#include <set>
#include <cmath>

using namespace std;

// 유클리드 호제법으로 두 수의 최대공약수 구하기
int gcdRecur(int a, int b)  {
    if (b == 0) {
        return a;
    }
    return gcdRecur(b, a%b);
}

// 집합에 있는 모든 수의 최대공약수 구하기
int getTotalGcd(set<int> s) {
    set<int>::iterator it = s.begin();
    int temp = *(it++); // 첫 번째 원소로 초기화
    
    // 집합의 모든 원소와 최대공약수 구하기
    while (it != s.end()) { // it가 집합의 끝에 도달할 때까지
        temp = gcdRecur(*(it++), temp); // it가 가리키는 원소와 temp의 최대공약수 구하기
    }
    
    return temp;
}

int main()
{
    int n = 0, s = 0;
    cin >> n >> s;
    set<int> distance;
    
    // set에 수빈이와 동생 간의 거리 넣기
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        distance.insert(abs(a - s));
    }
    
    cout << getTotalGcd(distance);

    return 0;
}