#include <iostream>
#include <map>
#include <vector>

using namespace std;

int findMaxLen(vector<int> &seq, int k) {
    // 숫자, 수열에 나온 횟수 저장할 맵 선언
    map<int, int> count;

    // window 사이즈를 1씩 증가시키며 중복된 숫자 값 카운트 업데이트
    // 처음 window 사이즈 : 1
    int first = 0;
    int last = 0;
    int max_len = 0;
    for (last = 0; last < seq.size(); last++) {
        // 이번 윈도우에서 추가되는 값
        count[seq[last]]++;

        // 중복된 숫자 값이 k개를 초과했을 경우
        while(count[seq[last]] > k) {
            // 윈도우 이동
            count[seq[first]]--;
            first++;
        }

        // 최댓값 갱신
        if(max_len < last - first + 1) {
            max_len = last - first + 1;
        }
    }
    return max_len;
}

int main() {
    // 입력
    int n, k;
    cin >> n >> k;

    vector<int> seq(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    // 연산 & 출력
    cout << findMaxLen(seq, k);
}