#include <iostream>
#include <queue>

using namespace std;

// 기다리는 사람 구조체
struct Man {
  int idx; // 처음 줄 선 순서
  int new_line_no; // 새로 선 줄 번호
  int days; // 근속일수
  int hurry; // 급한 정도
};

// 우선순위 비교 함수
struct cmp {
  bool operator()(const Man &child, const Man &parent) {
    if (parent.days != child.days) { // 근속일수가 다르면 근속일수 기준으로 비교
      return parent.days > child.days;
    }
    if (parent.hurry != child.hurry) { // 근속일수가 같으면 급한 정도 기준으로 비교
      return parent.hurry > child.hurry;
    }
    return parent.new_line_no < child.new_line_no; // 새로 선 줄 번호 기준으로 비교
  }
};

int main()
{
    int N, M, before_Deka;
    cin >> N >> M >> before_Deka;
    
    queue<Man> new_line[M]; // 새로 선 줄들
    
    for (int i = 0; i < N; i++) { // N명에 대해
      Man m;
      m.idx = i;
      m.new_line_no = i % M; // 새로 선 줄 번호
      cin >> m.days >> m.hurry;

      new_line[i % M].push(m); // 새로 선 줄에 사람 추가
    }
    
    priority_queue<Man, vector<Man>, cmp> pq; // 우선순위 큐
    for (int i = 0; i < M; i++) { // M개의 줄에 대해
      if (!new_line[i].empty()) {
        pq.push(new_line[i].front()); // 각 줄의 맨 앞 사람들 우선순위 큐에 추가
        new_line[i].pop(); // 줄에서 제거
      }
    }
    
    int count = 0;
    
    while (N--) { // N명에 대해
      Man top = pq.top(); // 우선순위 가장 높은 사람
      if (top.idx == before_Deka) { // 대카가 뽑혔으면
        cout << count;
        return 0;
      }

      count++; // 대카가 아니면 카운트 증가
      int out_line = top.new_line_no; // 뽑힌 사람의 줄 번호
      pq.pop(); // 우선순위 큐에서 제거
      if (!new_line[out_line].empty()) { // 뽑힌 사람의 줄에 사람이 남아있으면
        pq.push(new_line[out_line].front()); // 그 줄의 맨 앞 사람 우선순위 큐에 추가
        new_line[out_line].pop(); // 줄에서 제거
      }
    }
    
    return 0;
}