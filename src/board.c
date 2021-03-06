#include "board.h"
#include "printboard.h"
#include <stdio.h>
#include <stdlib.h>

void startboard(char board[][9], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            board[i][j] = '\0';
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
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
            if ((i == 8 - 8 && j == 1) || (i == 8 - 8 && j == 8))
                board[i][j] = 'r';
            if ((i == 8 - 8 && j == 2) || (i == 8 - 8 && j == 7))
                board[i][j] = 'n';
            if ((i == 8 - 8 && j == 3) || (i == 8 - 8 && j == 6))
                board[i][j] = 'b';
            if (i == 8 - 8 && j == 4)
                board[i][j] = 'q';
            if (i == 8 - 8 && j == 5)
                board[i][j] = 'k';
            // MELKIE
            if (i == 8 - 2)
                board[i][j] = 'P';
            if ((i == 8 - 1 && j == 1) || (i == 8 - 1 && j == 8))
                board[i][j] = 'R';
            if ((i == 8 - 1 && j == 2) || (i == 8 - 1 && j == 7))
                board[i][j] = 'N';
            if ((i == 8 - 1 && j == 3) || (i == 8 - 1 && j == 6))
                board[i][j] = 'B';
            if (i == 8 - 1 && j == 4)
                board[i][j] = 'Q';
            if (i == 8 - 1 && j == 5)
                board[i][j] = 'K';
        }
}

char WhPesh(char board[][9], int n, char hod[10])
{
    int i, k = 0, t, t1, p1, p2;
    for (i = 1; i < n; i++)
        if (hod[0] == board[8][i])
            t = i;

    for (i = 1; i < n; i++)
        if (hod[3] == board[8][i])
            t1 = i;

    p1 = 8 - (hod[1] - 48);
    p2 = 8 - (hod[4] - 48);

    if (board[p2][t1] == '\0') {
        for (p1--; p1 >= p2; p1--)
            if (board[p1][t] != '\0')
                k++;
        if ((hod[4] - hod[1] > 2) || (board[board[0][0] - hod[1]][t] != 'P')
            || (hod[0] != hod[3]) || (k != 0)) {
            printf("Incorrect hod \n");
            return 1;
        } else {
            board[board[0][0] - hod[1]][t] = '\0';
            board[board[0][0] - hod[1] - (hod[4] - hod[1])][t] = 'P';
            return 2;
        }
    }
    return 0;
}
char BlPesh(char board[][9], int n, char hod[10])
{
    int i, k = 0, t, t1, p1, p2;
    for (i = 1; i < n; i++)
        if (hod[0] == board[8][i])
            t = i;

    for (i = 1; i < n; i++)
        if (hod[3] == board[8][i])
            t1 = i;

    p1 = 8 - (hod[1] - 48);
    p2 = 8 - (hod[4] - 48);

    if (board[p2][t1] == '\0') {
        for (p1--; p1 >= p2; p1--)
            if (board[p1][t] != '\0')
                k++;
        if ((hod[1] - hod[4] > 2) || (board[board[0][0] - hod[1]][t] != 'p')
            || (hod[0] != hod[3]) || (k != 0)) {
            printf("Incorrect hod \n");
            return 1;
        } else {
            board[board[0][0] - hod[1]][t] = '\0';
            board[board[0][0] - hod[1] - (hod[4] - hod[1])][t] = 'p';
            return 2;
        }
    }
    printf("\n");
    return 0;
}
char WhiteK(char board[][9], int n, char hod[10])
{
    int i, p1, p2, t, t1, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for (i = 1; i < n; i++)
        if (hod[0] == board[8][i])
            t = i;
    for (i = 1; i < n; i++)
        if (hod[3] == board[8][i])
            t1 = i;
    p1 = 8 - (hod[1] - 48);
    p2 = 8 - (hod[4] - 48);

    if (board[p2][t1] == '\0') {
        f1 = p1 + 1;
        f2 = p1 - 1;
        f3 = t - 1;
        f4 = t + 1;

        if ((f1 == p2 && f3 == t1) || (f1 == p2 && f4 == t1)
            || (f2 == p2 && f3 == t1) || (f2 == p2 && f4 == t1)
            || (f1 == p2 && t == t1) || (f2 == p2 && t == t1)
            || (p1 == p2 && f3 == t1) || (p1 == p2 && f4 == t1)) {
            board[p1][t] = '\0';
            board[p2][t1] = 'K';
            return 2;
        } else {
            return 1;
        }
    } else
        return 1;
    return 0;
}
char BlackK(char board[][9], int n, char hod[10])
{
    int i, p1, p2, t, t1, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for (i = 1; i < n; i++)
        if (hod[0] == board[8][i])
            t = i;
    for (i = 1; i < n; i++)
        if (hod[3] == board[8][i])
            t1 = i;
    p1 = 8 - (hod[1] - 48);
    p2 = 8 - (hod[4] - 48);

    if (board[p2][t1] == '\0') {
        f1 = p1 + 1;
        f2 = p1 - 1;
        f3 = t - 1;
        f4 = t + 1;

        if ((f1 == p2 && f3 == t1) || (f1 == p2 && f4 == t1)
            || (f2 == p2 && f3 == t1) || (f2 == p2 && f4 == t1)
            || (f1 == p2 && t == t1) || (f2 == p2 && t == t1)
            || (p1 == p2 && f3 == t1) || (p1 == p2 && f4 == t1)) {
            board[p1][t] = '\0';
            board[p2][t1] = 'k';
            return 2;
        } else
            return 1;
    } else
        return 1;
    return 0;
}
int Queue(int k, char board[9][9], char boardtemp[9][9], char hod[10], int n)
{
    int i, j, f = 0, t = 0;
    t = k;
    for (i = 0; i < 8; i++) {
        for (j = 1; j < 9; j++) {
            if (boardtemp[i][j] != board[i][j]) {
                f++;
            }
        }
    }
    if (f > 0)
        k++;
    for (i = 0; i < n; i++)
        hod[i] = '\0';
    if (f == 0) {
        printf("Incorrect hod\n");
        return t;
    }
    f = 0;
    return k;
}
