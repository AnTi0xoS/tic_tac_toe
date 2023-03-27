#pragma once
#include <iostream>
using namespace std;

template<typename T>
bool checkWinStrategyAI(T board, char AI, char currentMove, char player)
{
    if (board[1][1] == AI)
    {
        if (board[2][1] == AI && board[2][0] != player && board[2][2] != player && board[0][2] != player)
        {
            board[2][0] = AI;
            currentMove += 1;
            return true;
        }
        else if (board[1][2] == AI && board[2][2] != player && board[0][0] != player && board[0][2] != player)
        {
            board[2][2] = AI;
            currentMove += 1;
            return true;
        }
        else if (board[0][1] == AI && board[0][2] != player && board[0][0] != player && board[2][0] != player)
        {
            board[0][2] = AI;
            currentMove += 1;
            return true;
        }
        else if (board[1][0] == AI && board[0][0] != player && board[2][0] != player && board[2][2] != player)
        {
            board[0][2] = AI;
            currentMove += 1;
            return true;
        }
    }
    return false;
}

template<typename T>
void randomMoveAI(T board, char AI)
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
