/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Word Search 
*             : https://leetcode.com/problems/word-search/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int **visited;
    char **board;
    char *word;
    int rowSize;
    int colSize;
    int nums;
} Status;

void initStatus(Status *status, char **board, char *word, int rowSize, int colSize) {
    if (status->visited = (int **)malloc(sizeof(int *)* rowSize)) {
        int i;
        for (i = 0; i < rowSize; ++i) {
            status->visited[i] = (int *)calloc(colSize, sizeof(int));
        }
        status->rowSize = rowSize;
        status->colSize = colSize;
        status->nums = 0;
        status->board = board;
        status->word = word;
    }
}

bool checkValid(Status *status, int irow, int icol) {
    char ch = status->board[irow][icol];
    if (status->visited[irow][icol])    return false;
    if (ch != status->word[status->nums])   return false;
    status->nums += 1;
    status->visited[irow][icol] = 1;
    return true;
}

void resetTracking(Status *status, int irow, int icol) {
    char ch = status->board[irow][icol];
    status->nums -= 1;
    status->visited[irow][icol] = 0;
}

bool backTracking(Status *status, int irow, int icol) {
    if (!status->word[status->nums]) return true;
    int dir[2][4] = { // four direction
        {-1, 0, 1,  0},
        { 0, 1, 0, -1} };
    int i, row, col;
    for (i = 0; i < 4; ++i) {
        row = irow + dir[0][i];
        col = icol + dir[1][i];
        if (row >= 0 && row < status->rowSize && col >= 0 && col < status->colSize) {
            if (checkValid(status, row, col)) {
                if (backTracking(status, row, col))  return true;
                resetTracking(status, row, col);
            }
        }
    }
    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    if (!board || !boardColSize || !boardRowSize)   return false;
    if (!word || !*word)  return true;
    Status status;
    initStatus(&status, board, word, boardRowSize, boardColSize);

    int i, j;
    for (i = 0; i < boardRowSize; ++i) {
        for (j = 0; j < boardColSize; ++j) {
            if (checkValid(&status, i, j)) {
                if (backTracking(&status, i, j))
                    return true;
                resetTracking(&status, i, j);
            }
        }
    }

    return false;                                                            
}

int main() {
    int boardRowSize = 3, boardColSize = 4;
    char *board[3];
    board[0] = "ABCE";
    board[1] = "SFCS";
    board[2] = "ADEE";
    char *word = "ADFCS";
    if (exist(board, boardRowSize, boardColSize, word)) {
        printf("Yes!\n");
    } else {
        printf("No!\n");
    }
    system("pause");
    return 0;
}
