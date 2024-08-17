#include "gameplay.h"
#include "gameboard.h"
#include <stdio.h>
#include <stdlib.h>


void setting_up_board(int board[MAX_ROWS][MAX_COLS], int num_rows, int num_cols){
    for (int i = 0; i < num_rows; i++){
        for (int j = 0; j < num_cols; j++){
            board[i][j] = 0;
        }
    }
}

int validate_input(int argc, char* argv[], int* num_rows, int* num_cols, int* num_pieces){
    //check for correct number of arguments
    if (argc != 4){
        printf("Not enough arguments entered\nUsage: %s num_rows num_cols num_pieces\n", argv[0]);
        return 1;
    }
    if (sscanf(argv[1], "%d", num_rows) != 1 || *num_rows <= 0){
        printf("Not enough arguments entered, PLease enter pos integers.\n");
        return 1;
    }

    if (sscanf(argv[2], "%d", num_cols) != 1 || *num_cols <= 0){
        printf("Not enough arguments entered");
        return 1;
    }
    if (sscanf(argv[3], "%d", num_pieces) != 1 || *num_pieces <= 0){
        printf("Invalid val for num_pieces)");
        return 1;
    }
    return 0;
}

int validate_real_number(const char* message_to_user, int max_num){
    int input;
    while(1) {
        printf("%s", message_to_user);
        if (scanf("%d", &input) == 1 && input >= 0 && input <= max_num){
            return input;
        } else {
            int clear;
            while ((clear = getchar()) != '\n' && clear != EOF);
            printf("Invalid input ");
        }
    }
}

//function for the main game
void main_game(int num_rows, int num_cols, int num_pieces){
    // keep track of player
    int turn = 1;
    //variable to store the winner
    int winner = 0;
    int board[MAX_ROWS][MAX_COLS];

    setting_up_board(board, num_rows, num_cols);

    while (1){
        //print the current board
        print_board(board, num_rows, num_cols);
        printf("Enter a column between 0 and %d: ", num_cols - 1);
        make_move(board, validate_real_number("", num_cols-1), turn, num_rows, num_cols);

        if (check_board(board, num_pieces, num_rows, num_cols)){
            winner = turn;
            break;
        }
    //check if the game is tie
        if (check_tie(board, num_rows, num_cols)){
        break;
        }

    //switch to players turn
        turn = 3 - turn;
    }
    print_board(board, num_rows, num_cols);

    //declare the winner or tie
    if (winner != 0){
        printf("Player %d Won!\n", winner);
    } else {
        printf("Tie game!\n");
    }
}




//functions related to gameplay
void make_move(int board[MAX_ROWS][MAX_COLS], int column, int turn, int num_rows, int num_cols){
    if (column <= num_cols - 1 && is_top_empty(board, column, num_rows)) { 
        board[drop_piece(board, column, num_rows)][column] = player_turn(turn);
    } else{ 
        int move = validate_real_number("Enter the column you want to play in: ", num_cols);
        make_move(board, move, turn, num_rows, num_cols);
    }
}

int check_board(int board[MAX_ROWS][MAX_COLS], int pieces, int num_rows, int num_cols){
    return vertical_win(board, pieces, num_rows, num_cols) || horizontal_win(board, pieces, num_rows, num_cols);
}

int vertical_win(int board[MAX_ROWS][MAX_COLS], int pieces, int num_rows, int num_cols){
    if (num_rows < pieces) {
    return 0;

    }
        for (int i = 0; i < num_rows; i++){
            for(int j = 0; j < num_cols; j++){
                int symbol = board[i][j];
                if (symbol == 0) {
                    continue;
                }
                int num_in_row = 1;
                for (int k = i + 1; k < num_rows; k++){
                    if (symbol == board[k][j]){
                        num_in_row++;
                        if(num_in_row == pieces) {
                            return 1;
                        }
                        continue;
                    } else {
                        break;
                    }
                }
            }
        }
        return 0;
}

int horizontal_win(int board[MAX_ROWS][MAX_COLS], int pieces, int num_rows, int num_cols) {
    if (num_cols < pieces) {
        return 0;
    }

    for (int i = 0; i < num_rows; i++){
        for ( int j = 0; j < num_cols; j++){
            int symbol = board[i][j];
            if (symbol == 0){
            continue;
            }
            int num_in_row = 1;

            for (int k = j + 1; k < num_cols; k++){
                if (symbol == board[i][k]){
                    num_in_row++;
                    if (num_in_row == pieces){
                        return 1;
                    } 
                    continue;
                } else {
                    break;
                }
            }
        }
    }
    return 0;
} 

int left_diagonal_win(int board[MAX_ROWS][MAX_COLS], int pieces, int num_rows, int num_cols){
    int overall_num;

    if(num_rows < num_cols){
        overall_num = num_rows;
    } else{
        overall_num = num_cols;
    }

    if (overall_num < pieces){
        return 0;
    }
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++){
            int symbol = board[i][j];
            if (symbol == 0){
                continue;
            }
            int num_in_row = 1;
            for (int k = 1; k < pieces; k++){
                if (i + k < num_rows && j + k < num_cols && symbol == board[i + k][j + k]){
                    num_in_row++;
                    if (num_in_row == pieces - 1) {
                        return 1;
                    }
                    continue;
                } else {
                    break;
                } 
            }
        }
    }
    return 0;
} 
void print_header(int num_cols){
    printf(" ");
    for(int i = 0; i < num_cols; i++){
        if (i + 1 == num_cols){
            printf("%d ", i);
        } else {
            printf("%d ", i);
        }
    }
    printf("\n");
} 
int check_tie(int board[MAX_ROWS][MAX_COLS], int num_rows, int num_cols){
    for (int i = 0; i < num_rows; i++){
        for (int j = 0; j < num_cols; j++){
            if (board[i][j] == 0) {
                //if there is any empty cell the game is not a tie
                return 0;   
            }
        }
    }
    //game is a tie
    return 1;
}

char player_turn(int turn){
    if (turn % 2 == 1){
        return 'X';
    } else {
        return 'O';
    }
}
        

    
