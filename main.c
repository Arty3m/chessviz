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

int main()
{
    char board[9][9];
    system("PAUSE");
    return 0;
}
