#include <stdio.h>
#include <unistd.h> // for write function
#include <stdlib.h> // for abs function

int ft_ten_queens_puzzle(void);
void nqueen(int board[], int row, int *count);
int is_safe(int board[], int r, int c);
int ft_abs(int n);
void print_res(int board[]);

int main() {
    int x = ft_ten_queens_puzzle();
    printf("Total solutions: %d\n", x);
    return 0;
}
int ft_abs(int n)
{
    if (n<0)return -n;
    return n;
}
void print_res(int board[]) {
    int i = 0;
    while (board[i] <10) {
        char c = board[i] + '0'; // Convert the column index to a character
        write(1, &c, 1);
        i++;
    }
    write(1, "\n", 1);
}

int is_safe(int board[], int r, int c) {
    int i = 0;
    while (i < r) {
        if (board[i] == c || ft_abs(i - r) == ft_abs(board[i] - c)) {
            return 0;
        }
        i++;
    }
    return 1;
}

int ft_ten_queens_puzzle(void) {
    int board[10] = {-1}; // Initialize the board with -1 indicating no queen placed yet
    int count = 0;
    nqueen(board, 0, &count);
    return count;
}

void nqueen(int board[], int r, int *count) {
    if (r == 10) { // Base case: all queens are successfully placed
        print_res(board);
        (*count)++;
        return;
    }

    int c = 0;
    while (c < 10) {
        if (is_safe(board, r, c)) {
            board[r] = c; // Place queen at row r, column c
            nqueen(board, r + 1, count); // Recur for next row
            board[r] = -1; // Backtrack
        }
        c++;
    }
}
