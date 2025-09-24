#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//큰 수의 덧셈 함수
stack<int> largeSum(stack<int>& a, stack<int>& b) {
    stack<int> s; //작은 자릿수부터 쌓이는 스택 
    int sum; //각 자리의 합 
    int rnd = 0; //올림수 존재
    
    //a와 b 중 하나라도 비어있지 않다면 계속해서 순회 
    while (!a.empty() || !b.empty()) {
        int x = 0, y = 0;
        
        //비어있지 않다면 가장 위의 원소를 저장하고 삭제 
        if (!a.empty()) {
            x = a.top();
            a.pop();
        }
        if (!b.empty()) {
            y = b.top();
            b.pop();
        }
        
        //각 자리의 합을 스택에 저장 (이전 자리에서의 올림수까지 합함)
        sum = x + y + rnd;
        s.push(sum % 10);
        
        if (sum > 9) { //이번 자리에서 올림수가 발생한다면 표시해둠 
            rnd = 1;
        } else {
            rnd = 0;
        }
    }
    //순회가 끝난 뒤 마지막 올림수 반영
    if (rnd == 1) {
        s.push(1);
    }
    
    return s;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    stack<int> a, b;
    
    //string으로 받은 숫자를 stack에 높은 자리수부터 int로 변환하여 push
    for (char c : s1) {
        a.push(c - '0');
    }
    for (char c : s2) {
        b.push(c - '0');
    }
    
    stack<int> result = largeSum(a, b);
    
    //출력
    while(!result.empty()) {
        cout << result.top();
        result.pop();
    }
    
    return 0;
}