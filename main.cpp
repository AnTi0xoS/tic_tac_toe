#include <iostream>
#include "GameEngine.h"
#include "AI.h"
using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int possibleInput[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
char player = 'X';
bool gameOver = false;
bool incorrect = false;

char gameMode = 'P';
char AI = 'O';
char currentMove = '1';

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
            default: randomMoveAI(board, AI); break;
            }
            currentMove += 1;
            return;
        }
        case 3:
            if (checkWinStrategyAI(board, AI, currentMove, player)) return;
            else
            {
                randomMoveAI(board, AI);
                currentMove += 1;
                break;
            }
        default:
        {
            randomMoveAI(board, AI);
            currentMove += 1;
            break;
        }
        }
    }
    else
    {
        randomMoveAI(board, AI);
        currentMove += 1;
    }
    return;
}

int main()
{
    cout << "Write 'P' to play with another player or 'B' to play with a bot" << endl;
    cin >> gameMode;

    if (gameMode == 'P') {
        while (!gameOver) {
            int pos;
            drawBoard(board);
            cout << "Player " << player << ", enter a position (1-9): ";
            cin >> pos;
            bool correctInput = false;
            for (int i = 0; i < 9; i++)
            {
                if (pos == possibleInput[i])
                {

                    correctInput = true;
                    break;
                }
            }
            if (!correctInput)
            {
                std::cout << "Incorrect step!" << std::endl;
                return 1;
            }
            markBoard(pos, board, player);

            if (checkWin(player, board)) {
                drawBoard(board);
                cout << "Player " << player << " wins!" << endl;
                gameOver = true;
            }
            else if (checkTie(board)) {
                drawBoard(board);
                cout << "Tie game!" << endl;
                gameOver = true;
            }
            else {
                togglePlayer(player);
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
            drawBoard(board);
            cout << "Player " << player << ", enter a position (1-9): ";
            cin >> pos;
            markBoard(pos, board, player);
            if (checkWin(player, board))
            {
                drawBoard(board);
                cout << "You win!" << endl;
                gameOver = true;
            }
            else if (checkTie(board)) {
                drawBoard(board);
                cout << "Tie game!" << endl;
                gameOver = true;
            }
            markBoardAI(pos);
            if (checkWin(AI, board))
            {
                drawBoard(board);
                cout << "You lose!" << endl;
                gameOver = true;
            }
            else if (checkTie(board)) {
                drawBoard(board);
                cout << "Tie game!" << endl;
                gameOver = true;
            }
        }
    }
    else {
       std::cout << "Incorrect step!" << std::endl;
    }
    return 0;
}
