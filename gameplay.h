#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#define MAX_ROWS 10
#define MAX_COLS 10

#include "gameboard.h"

int validate_input(int argc, char* argv[], int* num_rows, int* num_cols, int* num_pieces);
void main_game(int num_rows, int num_cols, int num_pieces);

// game board functions
void print_board(int board[MAX_ROWS][MAX_COLS], int num_rows, int num_cols);
int is_top_empty(int board[MAX_ROWS][MAX_COLS], int column, int num_rows);
int drop_piece(int board[MAX_ROWS][MAX_COLS], int column, int num_rows);

//gamepplay functions
void make_move(int board[MAX_ROWS][MAX_COLS], int column, int turn, int num_rows, int num_cols);
int check_board(int board[MAX_ROWS][MAX_COLS], int pieces, int num_rows, int num_cols);
int vertical_win(int board[MAX_ROWS][MAX_COLS], int pieces, int num_rows, int num_cols);
int horizontal_win(int board[MAX_ROWS][MAX_COLS], int pieces, int num_rows, int num_cols);
int left_diagonal_win(int board[MAX_ROWS][MAX_COLS], int pieces, int num_rows, int num_cols);
void print_header(int num_cols);
char player_turn(int turn);
int check_tie(int board[MAX_ROWS][MAX_COLS], int column, int num_rows);
int validate_real_number(const char* message_to_user, int max_num);

#endif
