#include <iostream>
#include <vector>

using namespace std;

int robotClean(vector<vector<int>> &map, int r, int c, int d) {
    // 북, 동, 남, 서 방향
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    // 청소 됐는지 안 됐는지 체크
    vector<vector<bool>> cleaned(map.size(), vector<bool>(map[0].size(), false));

    int cnt = 0;

    while(true) {
        // 1. 현재 위치 청소
        if(!cleaned[r][c]) {
            cleaned[r][c] = true;
            cnt++;
        }

        bool moved = false;
        
        // 3. 주변 4칸 중 청소되지 않은 칸 있는 경우
        for(int i = 0; i < 4; i++) {
            // 1. 반시계 방향으로 90도 회전
            int nd = (d + 3 - i) % 4;
            // 2. 바라보는 방향 기준으로 앞 칸으로 전진
            int nr = r + dr[nd];
            int nc = c + dc[nd];

            // 청소를 할 수 있는 경우
            if(map[nr][nc] == 0 && !cleaned[nr][nc]) {
                r = nr; c = nc; d = nd;
                moved = true;
                // 1번으로 돌아가기
                break;
            }
        }

        // 2. 주변 4칸 중 청소되지 않은 칸 없는 경우
        if(!moved) {
            // 진행 방향 기준 후진
            int bd = (d + 2) % 4;
            int br = r + dr[bd];
            int bc = c + dc[bd];

            // 후진할 수 있는 경우 (청소 되었어도 상관 없음)
            if(map[br][bc] == 0) {
                // 후진 후 1번으로 돌아가기
                r = br; c = bc;
            } else {
                // 후진할 수 없는 경우 작동 중지
                break;
            }
        }
    }
    return cnt;
}

int main() {
    // 입력
    int n, m, r, c, d;
    cin >> n >> m >> r >> c >> d;

    vector<vector<int>> map(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    // 연산 & 출력
    cout << robotClean(map, r, c, d);
}