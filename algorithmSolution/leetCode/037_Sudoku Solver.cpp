/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Sudoku Solver
*             : https://leetcode.com/problems/sudoku-solver/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DFS_search(char** board, int boardRowSize, int boardColSize, int x, int y) {
    int i, j, s_x = (x / 3) * 3, s_y = (y / 3) * 3, e_x = s_x + 3, e_y = s_y + 3;
    int size = boardRowSize > boardColSize ? boardRowSize + 1 : boardColSize + 1;
    int *used = (int *)calloc(size, sizeof(int));
    for (j = 0; j < boardRowSize; j++) {
        if (board[x][j] != '.') {
            used[board[x][j] - '0'] = 1;
        }
    }
    for (i = 0; i < boardColSize; i++) {
        if (board[i][y] != '.') {
            used[board[i][y] - '0'] = 1;
        }
    }
    for (i = s_x; i < e_x; i++) {
        for (j = s_y; j < e_y; j++) {
            if (board[i][j] != '.') {
                used[board[i][j] - '0'] = 1;
            }
        }
    }

    int next, board_size = boardColSize * boardRowSize;
    for (next = x * boardRowSize + y + 1; next < board_size; next++) {
        if (board[next / boardRowSize][next % boardRowSize] == '.') {
            break;
        }
    }

    for (i = 1; i <= size; i++) {
        if (!used[i]) {
            board[x][y] = '0' + i;
            if (next == board_size) {   //board is all filled
                return 1;
            }
            if (DFS_search(board, boardRowSize, boardColSize, next / boardRowSize, next % boardRowSize)) {
                return 1;
            }
        }
    }
    board[x][y] = '.';
    return 0;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    int i, j;
    for (i = 0; i < boardColSize; i++) {
        for (j = 0; j < boardRowSize; j++) {
            if (board[i][j] == '.') {
                DFS_search(board, boardRowSize, boardColSize, i, j);
                return;
            }
        }
    }
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int i, j, val, ik, jk;
    int ver[10] = { 0 }, hor[10] = { 0 }, sub[10] = { 0 };
    for (i = 0; i < 9; ++i) {
        memset(ver, 0, sizeof(ver));
        memset(hor, 0, sizeof(hor));
        memset(sub, 0, sizeof(sub));
        for (j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                val = board[i][j] - '0';
                if (ver[val])   return false;
                ver[val] = 1;
            }
            if (board[j][i] != '.') {
                val = board[j][i] - '0';
                if (hor[val])   return false;
                hor[val] = 1;
            }
            ik = (i % 3) * 3 + (j % 3);
            jk = (i / 3) * 3 + (j / 3);
            if (board[ik][jk] != '.') {
                val = board[ik][jk] - '0';
                if (sub[val])    return false;
                sub[val] = 1;
            }
        }
    }
    return true;
}

int main() {
    char *board[9];
    int i, j;
    for (i = 0; i < 9; i++)
        board[i] = (char *)malloc(sizeof(char)* 9);
    memcpy(board[0], ".....7..9", 9);
    memcpy(board[1], ".4..812..", 9);
    memcpy(board[2], "...9...1.", 9);
    memcpy(board[3], "..53...72", 9);
    memcpy(board[4], "293....5.", 9);
    memcpy(board[5], ".....53..", 9);
    memcpy(board[6], "8...23...", 9);
    memcpy(board[7], "7...5..4.", 9);
    memcpy(board[8], "531.7....", 9);
    bool ans = isValidSudoku(board, 9, 9);
    if (ans)    printf("YES!\n");
    else        printf("NO!\n");
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    board[1][1] = '0';
    solveSudoku(board, 9, 9);
    ans = isValidSudoku(board, 9, 9);
    if (ans)    printf("YES!\n");
    else        printf("NO!\n");
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");
    return 0;
}
