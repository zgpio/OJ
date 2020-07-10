#include <cstdio>
int Queenes[8], Counts = 0;

// (row,col)
// ┌───┬───┐
// │0,0│0,1│
// ├───┼───┤
// │1,0│1,1│
// └───┴───┘

int Check(int row, int col)
{
    for (int i = 0; i < row; i++) {
        int j = Queenes[i];
        if (col == j) {
            return 0;
        }
        if ((i + j) == (row + col)) { // ⧄
            return 0;
        }
        if ((i - j) == (row - col)) { // ⧅
            return 0;
        }
    }
    return 1;
}

// 打印棋盘
void print()
{
    for (int row = 0; row < 8; row++) {
        int col;
        for (col = 0; col < Queenes[row]; col++)
            printf("0");
        printf("#");
        for (col = Queenes[row] + 1; col < 8; col++) {
            printf("0");
        }
        printf("\n");
    }
    printf("==========\n");
}

// Queenes 只是用于存储棋盘
void eight_queen(int row)
{
    for (int col = 0; col < 8; col++) {
        if (Check(row, col)) {
            Queenes[row] = col;
            if (row == 7) {
                Counts++;
                print();
                return;
            }
            eight_queen(row + 1);
        }
    }
}
int main()
{
    // 调用回溯函数, 参数0表示从棋盘的第一行开始放置
    eight_queen(0);
    printf("摆放的方式有%d种", Counts);
    return 0;
}
