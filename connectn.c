#include "gameplay.h"
#include "gameboard.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int num_rows, num_cols, num_pieces;

    if(validate_input(argc, argv, &num_rows, &num_cols, &num_pieces) != 0){
        //error in input so exit
        return 1;
    } 
    main_game(num_rows, num_cols, num_pieces);
    return 0;
}


