#include <iostream>

using namespace std;

const int MAX = 19;

int board[MAX][MAX];
int left_x, left_y;

// 이동 방향 반대되는 방향은 선언 X
int dx[] = {0, 1, 1, 1};
int dy[] = {1, 1, 0, -1};

// 바둑판을 벗어나는 범위인지 아닌지 체크하는 함수
bool checkAvail(int x, int y) {
    return x >= 0 && x < MAX && y >= 0 && y < MAX;
}

bool checkWin(int x, int y, int color) {
    for (int i = 0; i < 4; i++) {
        int cnt = 1; // 연속된 바둑알의 갯수 매 반복문마다 초기화 시켜줌 (방향성 때문)
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 바둑판 범위 안에 있으면서 다음 바둑알도 같은 색상일 경우
        while(checkAvail(nx, ny) && board[nx][ny] == color) {
            cnt++;
            // 같은 방향으로 계속 진행
            nx += dx[i];
            ny += dy[i];
        }
        
        // cnt가 5이지만 만약 반대 방향으로 같은 색상이 있는 경우
        // 연속된 바둑알이 5개를 초과하므로 승리하지 못 함
        int px = x - dx[i];
        int py = y - dy[i];
        if(cnt == 5 && board[px][py] == color) {
            return false;
        }
        if(cnt == 5 && i == 3) { // i == 3인 경우 가로줄이 감소함
            // 가장 왼쪽에 있는 위치 업데이트
            left_x = nx - dx[i] + 1;
            left_y = ny - dy[i] + 1;
            return true;
        } else if(cnt == 5) {
            left_x = x + 1;
            left_y = y + 1;
            return true;
        }
    }
    return false;
    
}

int main() {
    // 입력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> board[i][j];
        }
    }

    // 연산 & 출력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            // 색깔 있는 돌이 나오면서 
            if(board[i][j] != 0 && checkWin(i, j, board[i][j])) {
                cout << board[i][j] << "\n";
                cout << left_x << " " << left_y;
                return 0;
            }
        }
    }

    // 아무도 이기지 못 한 경우
    cout << "0\n";
}