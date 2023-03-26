#include <iostream>
#include <cassert>
using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char player = 'X';
bool gameOver = false;
bool incorrect = false;

char gameMode = 'P';
char AI = 'O';
char currentMove = '1';

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

bool checkWin(char player) {
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

bool checkPossibleWin(char current)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == current && board[i][1] == current && board[i][2] != player && board[i][2] != AI)
        {
            board[i][2] = AI;
            return true;
        }
        if (board[i][1] == current && board[i][2] == current && board[i][0] != player && board[i][0] != AI)
        {
            board[i][0] = AI;
            return true;
        }
        if (board[i][0] == current && board[i][2] == current && board[i][1] != player && board[i][1] != AI)
        {
            board[i][1] = AI;
            return true;
        }
        if (board[0][i] == current && board[1][i] == current && board[2][i] != player && board[2][i] != AI)
        {
            board[2][i] = AI;
            return true;
        }
        if (board[1][i] == current && board[2][i] == current && board[0][i] != player && board[0][i] != AI)
        {
            board[0][i] = AI;
            return true;
        }
        if (board[0][i] == current && board[2][i] == current && board[1][i] != player && board[1][i] != AI)
        {
            board[1][i] = AI;
            return true;
        }
    }
    if (board[0][0] == current && board[1][1] == current && board[2][2] != player && board[2][2] != AI)
    {
        board[2][2] = AI;
        return true;
    }
    if (board[1][1] == current && board[2][2] == current && board[0][0] != player && board[0][0] != AI)
    {
        board[0][0] = AI;
        return true;
    }
    if (board[0][0] == current && board[2][2] == current && board[1][1] != player && board[1][1] != AI)
    {
        board[1][1] = AI;
        return true;
    }

    if (board[2][0] == current && board[1][1] == current && board[0][2] != player && board[0][2] != AI)
    {
        board[0][2] = AI;
        return true;
    }
    if (board[1][1] == current && board[0][2] == current && board[2][0] != player && board[2][0] != AI)
    {
        board[2][0] = AI;
        return true;
    }
    if (board[2][0] == current && board[0][2] == current && board[1][1] != player && board[1][1] != AI)
    {
        board[1][1] = AI;
        return true;
    }
    return false;
}

bool checkWinStrategyAI()
{
    if (board[1][1] == AI)
    {
        if (board[2][1] == AI && board[2][0] != player && board[2][2] != player && board[0][2] != player)
        {
            board[2][0] == AI;
            currentMove += 1;
            return true;
        }
        else if (board[1][2] == AI && board[2][2] != player && board[0][0] != player && board[0][2] != player)
        {
            board[2][2] == AI;
            currentMove += 1;
            return true;
        }
        else if (board[0][1] == AI && board[0][2] != player && board[0][0] != player && board[2][0] != player)
        {
            board[0][2] == AI;
            currentMove += 1;
            return true;
        }
        else if (board[1][0] == AI && board[0][0] != player && board[2][0] != player && board[2][2] != player)
        {
            board[0][2] == AI;
            currentMove += 1;
            return true;
        }
    }
    return false;
}

void randomMoveAI()
{
    bool correctValue = false;
    while (!correctValue)
    {
        srand(time(NULL));
        int x = rand() % 3;
        int y = rand() % 3;
        if (board[x][y] != 'X' && board[x][y] != 'O')
        {
            board[x][y] = AI;
            correctValue = true;
            break;
        }
    }
}

void markBoardAI(int pos)
{
    if (checkPossibleWin(AI)) return;
    if (checkPossibleWin(player)) return;
    if (AI == 'O' && board[1][1] == '5')
    {
        board[1][1] = AI;
        currentMove += 1;
        return;
    }
    else if (AI == 'X')
    {
        switch (currentMove)
        {
        case 2: {
            switch (pos)
            {
            case 2: board[1][2] = AI; break;
            case 4: board[0][1] = AI; break;
            case 6: board[2][1] = AI; break;
            case 8: board[1][0] = AI; break;
            default: randomMoveAI(); break;
            }
            currentMove += 1;
            return;
        }
        case 3:
            if (checkWinStrategyAI) return;
            else
            {
                randomMoveAI();
                currentMove += 1;
                break;
            }
        default:
        {
            randomMoveAI();
            currentMove += 1;
            break;
        }
        }
    }
    else
    {
        randomMoveAI();
        currentMove += 1;
    }
    return;
}

int main() {
    cout << "Write 'P' to play with another player or 'B' to play with a bot" << endl;
    cin >> gameMode;
    if (gameMode == 'P')
    {
        while (!gameOver) {
            int pos;
            drawBoard();
            cout << "Player " << player << ", enter a position (1-9): ";
            cin >> pos;
            markBoard(pos);

            if (checkWin(player)) {
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
    }
    else if (gameMode == 'B')
    {
        cout << "Write who you want to play ('X' or 'O')" << "\n" << "'X' goes first, 'O' goes second" << endl;
        cin >> player;
        if (player == 'X') AI = 'O';
        else AI = 'X';
        if (AI == 'X')
        {
            board[1][1] = AI;
            currentMove += 1;
        }
        while (!gameOver)
        {
            int pos;
            drawBoard();
            cout << "Player " << player << ", enter a position (1-9): ";
            cin >> pos;
            markBoard(pos);
            if (checkWin(player))
            {
                drawBoard();
                cout << "You win!" << endl;
                gameOver = true;
            }
            else if (checkTie()) {
                drawBoard();
                cout << "Tie game!" << endl;
                gameOver = true;
            }
            markBoardAI(pos);
            if (checkWin(AI))
            {
                drawBoard();
                cout << "You lose!" << endl;
                gameOver = true;
            }
            else if (checkTie()) {
                drawBoard();
                cout << "Tie game!" << endl;
                gameOver = true;
            }
        }
    }
    else {
        incorrect = true;
        std::cout << "Incorrect step!" << std::endl;
    }
    return 0;
}

int test1() {
    markBoard(1);
    assert(board[0][0] == 'X');
    togglePlayer();
    assert(player == 'O');
    return 0;
}

int test2() {
    markBoard(1);
    incorrect = false;
    markBoard(1);
    assert(incorrect == true);
    return 0;
}

int test3() {
    markBoard(1);
    togglePlayer();
    markBoard(2);
    togglePlayer();
    markBoard(3);
    togglePlayer();
    markBoard(4);
    togglePlayer();
    markBoard(6);
    togglePlayer();
    markBoard(5);
    togglePlayer();
    markBoard(7);
    togglePlayer();
    markBoard(9);
    togglePlayer();
    markBoard(8);
    assert(checkTie() == true);
    return 0;
}

