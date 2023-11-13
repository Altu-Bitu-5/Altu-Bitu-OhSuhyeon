#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// 총 소요시간이 time일 때 카운터가 수용할 수 있는 사람 수 체크
bool possible(ll time, vector<ll> &counter_time, int num) {
    ll people_cnt = 0;

    for (auto c_time : counter_time) {
        people_cnt += time / c_time;
    }
    return people_cnt >= num;
}

// 소요 시간의 최솟값 구하기
ll binarySearch(ll left, ll right, int num, vector<ll> &counter_time) {
    ll mid = 0;
    while(left <= right) {
        mid = (left + right) / 2;

        // 총 소요시간을 mid로 했을 때 가능한지 확인해야 함
        if(possible(mid, counter_time, num)) {
            // 소요 시간 더 줄일 수 있음
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return right + 1;
}

int main() {
    // 입력
    int counter, num;
    cin >> counter >> num;

    vector<ll> counter_time(counter, 0);

    for(int i = 0; i < counter; i++) {
        cin >> counter_time[i];
    }

    // 연산
    sort(counter_time.begin(), counter_time.end());

    // 연산 & 출력
    // 최소 시간 : 0
    ll left = 0;
    // 최대 시간 : 인원수 * 가장 짧게 걸리는 입국 심사 시간
    ll right = num * counter_time[0];
    cout << binarySearch(left, right, num, counter_time);
}