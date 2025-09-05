#include <bits/stdc++.h>
using namespace std;

int T, N, M, K;
string S;

// Hàm kiểm tra nếu đặt hố tại (hx, hy)
bool validHole(int hx, int hy, int N, int M, const string &S) {
    vector<vector<bool>> board(N, vector<bool>(M, true));
    board[hx][hy] = false;

    for (char move : S) {
        vector<vector<bool>> next(N, vector<bool>(M, false));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!board[i][j]) continue;
                int ni = i, nj = j;

                if (move == 'U') ni--;
                else if (move == 'D') ni++;
                else if (move == 'L') nj--;
                else if (move == 'R') nj++;

                if (ni >= 0 && ni < N && nj >= 0 && nj < M && !(ni == hx && nj == hy)) {
                    next[ni][nj] = true;
                }
            }
        }

        board = move(next);
    }

    // Sau thao tác, ô (hx, hy) vẫn là hố nếu không có kangaroo nào lọt vào đó
    return board[hx][hy] == false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        cin >> S;

        int count = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (validHole(i, j, N, M, S))
                    count++;

        cout << count << '\n';
    }

    return 0;
}
