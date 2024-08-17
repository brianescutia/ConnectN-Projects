#include "gameplay.h"
#include "gameboard.h"
#include <stdio.h>

void print_board(int board[MAX_ROWS][MAX_COLS], int num_rows, int num_cols){
    //print_board function here
    print_header(num_cols);

    for (int i = 0; i < num_rows; i++) {
        printf("%d", num_rows - (i + 1));

        for (int k = 0; k < num_cols; k++) {
            char current_character;
                if (board[i][k] == 0){
                    current_character = '*';
                    } else {
                        current_character = board[i][k];
                    } 
                    printf(" %c", current_character);
            }
            char end_char = ' ';
            printf("%c", end_char);
            printf("%c", '\n');
    }
}


int is_top_empty(int board[MAX_ROWS][MAX_COLS], int column, int num_rows){
    //is_top_empty function here
    return board[0][column] == 0;

}

int drop_piece(int board[MAX_ROWS][MAX_COLS], int column, int num_rows){
    //drop_piece function here
    for (int i = 0; i < num_rows; i++) {
        if (board[i][column] != 0) {
            return i - 1;
        }
    }
    return num_rows - 1;
}
