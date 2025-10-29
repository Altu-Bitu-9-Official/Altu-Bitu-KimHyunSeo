#include <iostream>
#include <string>

using namespace std;
int MASK = 0;

// add x
void add(int x_bit) {
	MASK = MASK | x_bit;
	return;
}

// remove x
void remove(int x_bit) {
	MASK = MASK & ~x_bit;
	return;
}

// check x
void check(int x_bit) {
	if (MASK & (x_bit)) { // & 연산 결과가 1이면 포함된 것
		cout << 1 << '\n';
	} else {
	  cout << 0 << '\n';
	}
	return;
}

// toggle x
void toggle(int x_bit) {
	MASK = MASK ^ x_bit;
	return;
}

// all
void all() {
	MASK = 0;
	int power = 1; // 2^0

	for (int i = 0; i <= 20; i++) { // 1~20까지 모두 포함
		MASK += power; // 2^i 더하기
		power *= 2;   // 다음 2^i 구하기
	}
	return;
}

// empty
void empty() {
	MASK = 0;
	return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
	int count = 0;
	cin >> count;
	
	for (int i = 0; i < count; i++) {
		string state;
		int x;

		cin >> state;

		if (state == "add") {
		  cin >> x;
			add(1 << x);
			continue;
		}
		if (state == "remove") {
		  cin >> x;
			remove(1 << x);
			continue;
		}
		if (state == "check") {
			cin >> x;
			check(1 << x);
			continue;
		}
		if (state == "toggle") {
		  cin >> x;
			toggle(1 << x);
			continue;
		}
		if (state == "all") {
			all();
			continue;
		}
		if (state == "empty") {
			empty();
			continue;
		}
	}

	return 0;
}