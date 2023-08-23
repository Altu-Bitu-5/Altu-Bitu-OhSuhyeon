#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {

    // 입력
    int t, n;
    cin >> t;

    // 서류 심사 순위를 key값으로, 면접 순위를 value값으로 갖는 해시맵 선언
    map<int, int> score;
    int score_1, score_2;

    // 테스트 케이스 갯수만큼 결과 계산
    for (int i = 0; i < t; i++) {
        cin >> n;
        int result = n; // 최대 전원 통과 가정

        for (int j = 0; j < n; j++) {
            cin >> score_1 >> score_2;
            // 서류 심사 순위 (score_1) 순으로 탐색할 수 있는 맵 생성
            score[score_1] = score_2;
        }

        // 맵을 탐색하며 면접 순위 비교
        int cmp = 1; // 비교 대상이 될 지원자의 서류 심사 순위
        for (int j = 2; j <= n; j++) {
            // 비교자의 면접 순위보다 현재 지원자의 면접 순위가 낮을 경우 탈락
            if(score[cmp] < score[j]) {
                result--; 
            }
            // 비교자의 면접 순위보다 높지만 바로 다음 등수가 아닐 경우 비교자 인덱스 변경
            else if(score[j] < score[cmp] - 1) {
                cmp = j;
                j = cmp;
            }
        }
        cout << result << '\n';
    }
    
}