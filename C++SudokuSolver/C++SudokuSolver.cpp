#include <iostream>
#include <vector>

using namespace std;

const int BOARD_SIZE = 9;

bool solveSudoku(vector<vector<int>>& board);
vector<int> findEmptyCell(vector<vector<int>>& board);
bool isValidMove(vector<vector<int>>& board, int row, int col, int num);

int main() {
    vector<vector<int>> puzzle = {
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 8, 0, 0, 0, 7, 0, 9, 0},
        {6, 0, 2, 0, 0, 0, 5, 0, 0},
        {0, 7, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 4, 0},
        {0, 0, 5, 0, 0, 0, 6, 0, 3},
        {0, 9, 0, 4, 0, 0, 0, 7, 0},
        {0, 0, 6, 0, 0, 0, 0, 0, 0}
    };

    if (solveSudoku(puzzle)) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                cout << puzzle[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}

bool solveSudoku(vector<vector<int>>& board) {
    vector<int> emptyCell = findEmptyCell(board);
  
    if (emptyCell.empty()) {
        // All cells are filled, puzzle is solved
        return true;
    }
  
    int row = emptyCell[0];
    int col = emptyCell[1];
  
    for (int num = 1; num <= 9; num++) {
        if (isValidMove(board, row, col, num)) {
            board[row][col] = num;
      
            if (solveSudoku(board)) {
                return true;
            }
      
            board[row][col] = 0;
        }
    }
  
    return false;
}

vector<int> findEmptyCell(vector<vector<int>>& board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == 0) {
                return {row, col};
            }
        }
    }
  
    return {};
}

bool isValidMove(vector<vector<int>>& board, int row, int col, int num) {
    // Check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
  
    // Check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
