#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row)
            cout << cell << " ";
        cout << endl;
    }
}

bool isValidMove(int x, int y, const vector<vector<int>>& board) {
    return x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == 0;
}

int getDegree(int x, int y, const vector<vector<int>>& board) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if (isValidMove(nx, ny, board))
            count++;
    }
    return count;
}

bool knightTour(int x, int y, int movei, vector<vector<int>>& board) {
    if (movei == 8 * 8 + 1)
        return true;

    vector<vector<int>> moveOptions;
    for (int i = 0; i < 8; ++i) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if (isValidMove(nx, ny, board)) {
            int deg = getDegree(nx, ny, board);
            moveOptions.push_back({nx, ny, deg});
        }
    }

    sort(moveOptions.begin(), moveOptions.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    for (const auto& option : moveOptions) {
        int nx = option[0];
        int ny = option[1];
        board[nx][ny] = movei;
        if (knightTour(nx, ny, movei + 1, board))
            return true;
        board[nx][ny] = 0;
    }
    return false;
}

int main() {
    int y, x;
    cin >> y >> x;
    x--; y--;
    vector<vector<int>> board(8, vector<int>(8, 0));
    board[x][y] = 1;
    if (knightTour(x, y, 2, board))
        printBoard(board);
    return 0;
}
