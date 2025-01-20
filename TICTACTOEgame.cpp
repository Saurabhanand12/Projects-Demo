#include <iostream>
using namespace std;

void drawBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
        return true;
    return false;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void computerMove(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player = 'X';
    int row, col;
    bool gameOver = false;

    while (!gameOver) {
        drawBoard(board);
        if (player == 'X') {
            cout << "Player " << player << ", enter row and column (0, 1, or 2): ";
            cin >> row >> col;
            if (board[row][col] == ' ') {
                board[row][col] = player;
                if (checkWin(board, player)) {
                    drawBoard(board);
                    cout << "Player " << player << " wins!\n";
                    gameOver = true;
                } else {
                    player = 'O';
                }
            } else {
                cout << "Cell already occupied! Try again.\n";
            }
        } else {
            computerMove(board);
            if (checkWin(board, player)) {
                drawBoard(board);
                cout << "Computer wins!\n";
                gameOver = true;
            } else {
                player = 'X';
            }
        }

        if (isBoardFull(board)) {
            drawBoard(board);
            cout << "It's a draw!\n";
            gameOver = true;
        }
    }

    return 0;
}
