#pragma once

int main();
void drawBoard();
void togglePlayer();
bool checkWin(char player);
bool checkTie();
void markBoard(int pos);
void markBoardAI(int pos);
bool checkPossibleWin(char current);