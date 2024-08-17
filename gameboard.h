#ifndef GAMEBOARD_H
#define GAMEBOARD_H

void print_board(int board[MAX_ROWS][MAX_COLS], int num_rows, int num_cols);
int is_top_empty(int board[MAX_ROWS][MAX_COLS], int column, int num_rows);
int drop_piece(int board[MAX_ROWS][MAX_COLS], int column, int num_rows);

#endif
