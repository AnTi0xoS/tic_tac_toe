#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char player = 'X';
bool gameOver = false;
bool incorrect = false;

void drawBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void togglePlayer() {
    if (player == 'X') {
        player = 'O';
    }
    else {
        player = 'X';
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

void markBoard(int pos) {
    if (pos == 1 && board[0][0] == '1') {
        board[0][0] = player;
    }

    else if (pos == 2 && board[0][1] == '2') {
        board[0][1] = player;
    }

    else if (pos == 3 && board[0][2] == '3') {
        board[0][2] = player;
    }

    else if (pos == 4 && board[1][0] == '4') {
        board[1][0] = player;
    }

    else if (pos == 5 && board[1][1] == '5') {
        board[1][1] = player;
    }

    else if (pos == 6 && board[1][2] == '6') {
        board[1][2] = player;
    }

    else if (pos == 7 && board[2][0] == '7') {
        board[2][0] = player;
    }

    else if (pos == 8 && board[2][1] == '8') {
        board[2][1] = player;
    }

    else if (pos == 9 && board[2][2] == '9') {
        board[2][2] = player;
    }
    else {
        incorrect = true;
        std::cout << "Incorrect step!" << std::endl;
    }
}

bool checkTie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    while (!gameOver) {
        int pos;
        drawBoard();
        cout << "Player " << player << ", enter a position (1-9): ";
        cin >> pos;
        markBoard(pos);

        if (checkWin()) {
            drawBoard();
            cout << "Player " << player << " wins!" << endl;
            gameOver = true;
        }
        else if (checkTie()) {
            drawBoard();
            cout << "Tie game!" << endl;
            gameOver = true;
        }
        else {
            togglePlayer();
        }
    }
    return 0;
}