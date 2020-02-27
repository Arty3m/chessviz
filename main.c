#include <stdio.h>
#include <stdlib.h>
void startboard(char board[9][9])
{
    int i, j;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++) {
            board[i][j] = '\0';
        }
}
void fillboard(char board[9][9])
{
    int i, j;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++) {
            if (j == 0) {
                board[0][j] = '8';
                board[1][j] = '7';
                board[2][j] = '6';
                board[3][j] = '5';
                board[4][j] = '4';
                board[5][j] = '3';
                board[6][j] = '2';
                board[7][j] = '1';
                board[8][j] = ' ';
            }
            if (i == 8) {
                board[i][0] = ' ';
                board[i][1] = 'a';
                board[i][2] = 'b';
                board[i][3] = 'c';
                board[i][4] = 'd';
                board[i][5] = 'e';
                board[i][6] = 'f';
                board[i][7] = 'g';
                board[i][8] = 'h';
            }
            // BOLSHIE
            if (i == 8 - 7)
                board[i][j] = 'p';
            if (i == 8 - 8 && j == 1 || i == 8 - 8 && j == 8)
                board[i][j] = 'r';
            if (i == 8 - 8 && j == 2 || i == 8 - 8 && j == 7)
                board[i][j] = 'n';
            if (i == 8 - 8 && j == 3 || i == 8 - 8 && j == 6)
                board[i][j] = 'b';
            if (i == 8 - 8 && j == 4)
                board[i][j] = 'q';
            if (i == 8 - 8 && j == 5)
                board[i][j] = 'k';
            // MELKIE
            if (i == 8 - 2)
                board[i][j] = 'P';
            if (i == 8 - 1 && j == 1 || i == 8 - 1 && j == 8)
                board[i][j] = 'R';
            if (i == 8 - 1 && j == 2 || i == 8 - 1 && j == 7)
                board[i][j] = 'N';
            if (i == 8 - 1 && j == 3 || i == 8 - 1 && j == 6)
                board[i][j] = 'B';
            if (i == 8 - 1 && j == 4)
                board[i][j] = 'q';
            if (i == 8 - 1 && j == 5)
                board[i][j] = 'k';
        }
}
void printboard(char board[9][9])
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}
int main()
{
    char board[9][9];
    startboard(board);
    fillboard(board);
    printboard(board);

    system("PAUSE");
    return 0;
}
