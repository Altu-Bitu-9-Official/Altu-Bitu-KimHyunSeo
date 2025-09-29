#include <iostream>
#include <string>
#include <stack>

using namespace std;

//괄호 짝 맞추기 함수
bool match(string& sent) {
    stack<char> s;
    
    for (char c : sent) { //문자열의 각 문자에 대해
        if (c == '(' || c == '[') { //여는 괄호라면 스택에 push
            s.push(c);
        }
        if (c == ')') { //닫는 괄호라면
            if (s.empty() || s.top() != '(') { //스택이 비어있거나 짝이 맞지 않으면 false
                return false;
            }
            s.pop(); //짝이 맞으면 pop
        }
        if (c == ']') {
            if (s.empty() || s.top() != '[') {
                return false;
            }
            s.pop();
        }
    }
    if (!s.empty()) { //순회가 끝난 뒤 스택이 비어있지 않다면 짝이 맞지 않는 것
        return false;
    }
    
    return true; //모든 괄호의 짝이 맞음
}

int main()
{
    string sent;

    while (true) {
        getline(cin, sent);

        if (sent == ".") { //입력이 .이라면 종료
            break;
        }

        if (match(sent)) {
            cout << "yes\n";
        } else {
            cout << "no\n";

        }
    }

    return 0;
}