#include <iostream>
#include <vector>
#include <set>

using namespace std;

int calcMaxSushi(vector<int> &sushi, int d, int k, int c) {
    set<int> sushiType;
    vector<int> count(d + 1, 0); // 초밥 가짓수 카운트

    // 윈도우 사이즈 만큼 셋에 추가
    for (int i = 0; i < k; i++) {
        sushiType.insert(sushi[i]);
        count[sushi[i]]++;
    }

    // 쿠폰으로 먹을 수 있는 초밥 종류 저장
    sushiType.insert(c);
    count[c]++;
    int max_num = sushiType.size();

    // 슬라이딩
    for (int i = k; i < sushi.size() + k - 1; i++) {
        int idx = i % sushi.size();

        // 이번 윈도우에서 제외되는 값
        count[sushi[i - k]]--;
        // 제외시켰을 때 이번 윈도우에 들어가지 않는 경우 셋에서 제외
        // 0이 아닌 경우에는 셋에 그대로 유지
        if(count[sushi[i - k]] == 0) {
            sushiType.erase(sushi[i - k]);
        }

        // 이번 윈도우에서 추가되는 값
        count[sushi[idx]]++;
        // 처음 추가되는 경우에는 셋에 추가시켜 줘야 함
        if(count[sushi[idx]] == 1) {
            sushiType.insert(sushi[idx]);
        }

        // 현재 셋의 사이즈가 초밥 종류 갯수와 동일하면 그대로 반환
        if(sushiType.size() == d) {
            return d;
        }

        // 최댓값 갱신
        if(max_num < sushiType.size()) {
            max_num = sushiType.size();
        }
    }
    return max_num;
}

int main() {
    // 입력
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> sushiCircle(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> sushiCircle[i];
    }

    // 연산 & 출력
    cout << calcMaxSushi(sushiCircle, d, k, c);
}