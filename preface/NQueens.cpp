//
// Created by 蒋澳然 on 2021/7/4.
//

#include "TimeMeasure.h"

class NQueens : public TimeMeasureExe {

    const char FLAG_QUEEN = 'Q';
    const char FLAG_GRID = 'X';

public:

    vector<vector<string>> nQueens{};

    void buildNQueens(int n) {
        nQueens.clear();
        vector<string> board(n, string(n, FLAG_GRID));
        backtrack(board, 0);
    }

    void backtrack(vector<string> &board, int row) {
        if (row == board.size()) {
            nQueens.push_back(board);
            return;
        }
        ul n = board[row].size();
        for (int i = 0; i < n; ++i) {
            if (!isValid(board, row, i)) {
                continue;
            }
            board[row][i] = FLAG_QUEEN;
            backtrack(board, row + 1);
            board[row][i] = FLAG_GRID;
        }
    }

    bool isValid(const vector<string> &board, int row, int column) const {
        // 查找同一列
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][column] == FLAG_QUEEN) {
                return false;
            }
        }
        // 查找左上角
        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == FLAG_QUEEN) {
                return false;
            }
        }
        // 查找右上角
        for (int i = row - 1, j = column + 1; i >= 0 && j < board[row].size(); i--, j++) {
            if (board[i][j] == FLAG_QUEEN) {
                return false;
            }
        }
        return true;
    }


    void exe() override {
        buildNQueens(8);
    }

};

/*
int main() {
    NQueens nQueens;
    timeMeasure->measureTime(nQueens);
    for (vector<string> &board: nQueens.nQueens) {
        printf("\n");
        for (string &line: board) {
            cout << line << endl;
        }
    }
}*/
