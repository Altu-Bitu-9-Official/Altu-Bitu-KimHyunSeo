#include <iostream>
#include <string>
#include <set>

using namespace std;

// set을 이용하여 중복 없이 부분 문자열의 개수를 세는 함수
int countSubstr(string& s) {
    set<string> st;
    int len = s.length();
    
    
    for (int i = 1; i <= len; i++) { // 부분 문자열의 길이
        for (int j = 0; j <= len - i; j++) { // 부분 문자열의 시작 위치
            st.insert(s.substr(j, i));
        }
    }
    
    return st.size();
}

int main()
{
    string s;
    cin >> s;
    
    int i = countSubstr(s);
    cout << i << '\n';

    return 0;
}