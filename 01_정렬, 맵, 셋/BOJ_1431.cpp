#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// 문자열 안의 숫자 더하기
int sumInt(string& s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            sum += s[i] - '0';
        }
    }
    return sum;
}

// 비교 함수 
bool comp(string& s1, string& s2) {
    if (s1.length() != s2.length()) { // 길이가 다르면 
        return s1.length() < s2.length(); // 짧은 순서대로 
    }
    int sum1 = sumInt(s1);
    int sum2 = sumInt(s2);
    if (sum1 != sum2) { // 숫자 합이 다르면 
        return sum1 < sum2; // 숫자 합이 작은 순서대로 
    }
    return s1 < s2; // 모두 같으면 글자순 
}

int main()
{
    int n;
    
    // 입력 
    cin >> n;
    vector<string> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // 정렬
    sort(v.begin(), v.end(), comp);
    
    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}