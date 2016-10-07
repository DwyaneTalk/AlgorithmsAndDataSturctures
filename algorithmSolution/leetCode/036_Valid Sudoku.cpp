/*   DwyaneTalk@gmail.com
*   by lutao
*   hihocoder : Valid Sudoku 
*             : https://leetcode.com/problems/valid-sudoku/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


bool isValidSudoku(char board[9][9]) {
    int i, j, val, ik, jk;
    int ver[10] = { 0 }, hor[10] = { 0 }, sub[10] = { 0 };
    for (i = 0; i < 9; ++i) {
        memset(ver, 0, sizeof(ver));
        memset(hor, 0, sizeof(hor));
        memset(sub, 0, sizeof(sub));
        for ( j = 0; j < 9; j++) {
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
    char board[9][9] = {
        '5','3','.','.','7','.','.','.','.',
        '6','.','.','1','9','5','.','.','.',
        '.','9','8','.','.','.','.','6','.',
        '8','.','.','.','6','.','.','.','3',
        '4','.','.','8','.','3','.','.','1',
        '7','.','.','.','2','.','.','.','6',
        '.','6','.','.','.','.','2','8','.',
        '.','.','.','4','1','9','.','.','5',
        '.','.','.','.','8','.','.','7','9'
    };
    bool ans = isValidSudoku(board);
    if (ans)
        printf("YES!\n");
    else
        printf("NO!\n");
    system("pause");
    return 0;
}
