#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// 가독성을 위해 손님 정보를 구조체로 관리
struct Person {
    int id; // 각 손님을 구별하기 위한 고유 ID
    int t1; // 예약 시간
    int t2; // 도착 시간
};

// 일반 대기열(wait_q)을 위한 비교 구조체
// 1. 도착 시간(t2)이 빠른 순서
// 2. 도착 시간이 같다면 예약 시간(t1)이 빠른 순서
struct CmpWait {
    bool operator()(const Person& a, const Person& b) const {
        if (a.t2 != b.t2) {
            return a.t2 > b.t2;
        }
        return a.t1 > b.t1;
    }
};

// VIP 호출 대기열(vip_calls) 내부에서 사용할 비교 구조체
// 동일한 예약 시간을 가진 VIP들 사이에서 도착 시간(t2)이 빠른 순서로 정렬
struct CmpVip {
    bool operator()(const Person& a, const Person& b) const {
        return a.t2 > b.t2;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Person> all_people(n);
    vector<vector<Person>> arrivals(300001);
    int max_time = 0;

    for (int i = 0; i < n; ++i) {
        all_people[i].id = i;
        cin >> all_people[i].t1 >> all_people[i].t2;
        arrivals[all_people[i].t2].push_back(all_people[i]);
        max_time = max({max_time, all_people[i].t1, all_people[i].t2});
    }

    // 일반 대기열: 도착 시간 -> 예약 시간 순서로 정렬되는 최소 힙
    priority_queue<Person, vector<Person>, CmpWait> wait_q;
    
    // VIP 호출 대기열: Key=예약시간(t1), Value=해당 시간에 예약한 VIP 목록 (도착 시간 순 정렬)
    map<int, priority_queue<Person, vector<Person>, CmpVip>> vip_calls;

    // 각 손님이 이미 서비스되었는지 여부를 추적 (Lazy Deletion 용)
    vector<bool> served(n, false);
    
    long long max_wait_time = 0;
    int served_count = 0;

    for (int t = 1; served_count < n; ++t) {
        // 1. 현재 시간에 도착한 손님들을 각 대기열에 추가
        if (t <= max_time) {
            for (const auto& p : arrivals[t]) {
                // 모든 손님은 일단 일반 대기열에 들어감
                wait_q.push(p);
                // VIP 자격(t2 <= t1)이 되면 VIP 호출 대기열에도 등록
                if (p.t2 <= p.t1) {
                    vip_calls[p.t1].push(p);
                }
            }
        }

        Person person_to_serve;
        bool should_serve = false;

        // 규칙 1: 오늘의 VIP가 있는지 확인 (절대 우선권)
        if (vip_calls.count(t)) {
            // 해당 시간에 예약한 VIP가 있다면, 그 중 가장 먼저 도착한 VIP를 선택
            person_to_serve = vip_calls[t].top();
            vip_calls.erase(t); // 호출된 VIP 그룹은 맵에서 제거
            should_serve = true;
        }
        // 규칙 2: 오늘의 VIP가 없다면, 일반 대기열에서 가장 우선순위 높은 손님 선택
        else {
            // 이미 처리된 손님은 건너뜀 (Lazy Deletion)
            while (!wait_q.empty() && served[wait_q.top().id]) {
                wait_q.pop();
            }

            if (!wait_q.empty()) {
                person_to_serve = wait_q.top();
                wait_q.pop();
                should_serve = true;
            }
        }
        
        // 3. 선택된 손님을 최종 처리
        if (should_serve) {
            served[person_to_serve.id] = true;
            max_wait_time = max(max_wait_time, (long long)t - person_to_serve.t2);
            served_count++;
        }
    }

    cout << max_wait_time << '\n';

    return 0;
}