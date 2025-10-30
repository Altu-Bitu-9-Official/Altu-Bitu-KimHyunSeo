#include <iostream>
#include <deque>
#include <queue>

using namespace std;

//0: dodo, 1: suyeon
vector<deque<int>> deck(2);
vector<deque<int>> ground(2);

// 카드 한 장을 내려놓는 함수
bool dropCard(bool player) {
  ground[player].push_front(deck[player].front());
  deck[player].pop_front();
  
  if (deck[player].empty()) { // 내려놨을 때 덱이 비어있으면 패배
    return false;
  }
  return true;
}

// 그라운드에 있는 카드를 덱으로 되돌리는 함수
void returnToDeck(bool player) {
  while (!ground[!player].empty()) { // 상대방 그라운드 카드 먼저 되돌리기
    deck[player].push_back(ground[!player].back());
    ground[!player].pop_back();
  }
  while (!ground[player].empty()) {
    deck[player].push_back(ground[player].back());
    ground[player].pop_back();
  }
  return;
}

// 게임을 진행하여 승자를 리턴하는 함수
int play(int &m) {
  bool player = 0; // 0: dodo, 1: suyeon
  
  while (m--) {
    if (!dropCard(player)) { // 카드를 내려놓고 덱이 비어있으면 패배
      return (!player); // 상대방이 승리
    }
    if (ground[player].front() == 5) { // 방금 낸 카드가 5이면
      returnToDeck(0); // 도도의 덱에 그라운드의 카드 모두 리턴 
    } else if (!ground[player].empty() && !ground[!player].empty()) { // 상대방 그라운드에 카드가 있을 때
      if (ground[player].front() + ground[!player].front() == 5) { // 두 카드의 합이 5이면
        returnToDeck(1); // 수연의 덱에 그라운드의 카드 모두 리턴
      }
    }

    player = !player;
  }
  
  int do_size = deck[0].size();
  int su_size = deck[1].size();
  
  if (do_size > su_size) {
    return 0;
  } else if (do_size < su_size) {
    return 1;
  } else {
    return -1; // 무승부
  }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      deck[0].push_front(x);
      deck[1].push_front(y);
    }
    
    int winner = play(m);
    
    if (winner == 0) {
      cout << "do";
    } else if (winner == 1) {
      cout << "su";
    } else {
      cout << "dosu";
    }

    return 0;
}