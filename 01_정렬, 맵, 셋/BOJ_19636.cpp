#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// 다이어트 시뮬레이션 함수
void diet(int weight, int base_e, int t, int d, int eat_e, int act_e, bool check) {
    int before_base_e = base_e;
    int use_e = base_e + act_e;

		// 다이어트 일수만큼 반복
    for (int x = 0; x < d; x++) {
        weight += eat_e - use_e;
        if (weight <= 0) {
            cout << "Danger Diet\n";
            return;
        }
        if (check) { // 일일 기초 대사량의 변화를 고려했을 때만 확인
            if (abs(eat_e - use_e) > t) {
                base_e += floor((double)(eat_e - use_e)/2);
                use_e = base_e + act_e;
            }
            if (base_e <= 0) {
	        cout << "Danger Diet\n";
	        return;
	        } 
        }
    }
    cout << weight << ' ' << base_e;
    
    if (check) { // 일일 기초 대사량의 변화를 고려했을 때만 확인
    	int result = before_base_e - base_e; // 다이어트 이전 값으로 계산했을 때 
    	if (result > 0) { // 더할 값이 양수이면 몸무게 증가
    	    cout << " YOYO\n";
    	} else {
    	    cout << " NO\n";
    	}
    } else {
        cout << '\n';
    }
    
    return;
}

int main()
{
	int weight0, before_base_e, t; //초기 몸무게, 전 기초대사량, 역치 
	int d, eat_e, act_e; // 다이어트 일수, 에너지 섭취량, 활동대사량

	cin >> weight0 >> before_base_e >> t;
	cin >> d >> eat_e >> act_e;
	
	diet(weight0, before_base_e, t, d, eat_e, act_e, false);
	diet(weight0, before_base_e, t, d, eat_e, act_e, true);

	return 0;
}