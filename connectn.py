def validate_real_number(message_to_user, max_num=-1):
    while True:
        input_num = input(message_to_user)
        if input_num.isnumeric() and ((max_num == -1 and int(input_num) >= 0) or (0 <= int(input_num) <= max_num)):
            return int(input_num)
        else:
            continue


def make_move(board, column, turn):
    if column <= num_of_cols(board) - 1 and is_top_empty(board, column):
        board[drop_piece(board, column)][column] = player_turn(turn)
    else:
        move = validate_real_number("Enter the column you want to play in: ", num_of_cols(board))
        make_move(board, move, turn)
    return board


def drop_piece(board, column):
    for i in range(0, num_of_rows(board)):
        if board[i][column] != 0:
            return i - 1
    return num_of_rows(board) - 1


# check if the top of column is empty (or not full)
def is_top_empty(board, column):
    return board[0][column] == 0


def is_column_empty(board, column):
    for i in range(0, num_of_rows(board)):
        if board[i][column] != 0:
            return i
    return -1


# based on game turn, determine which player symbol to use
def player_turn(turn):
    if turn % 2 == 1:
        return 'X'
    else:
        return 'O'


def num_of_rows(board):
    return len(board)


def num_of_cols(board):
    return len(board[0])


# print the game board to the terminal
def print_board(board):
    print_header(board)
    for i in range(num_of_rows(board)):
        for j in range(-1, num_of_cols(board)):
            if j + 1 == num_of_cols(board):
                end_char = ''
            else:
                end_char = ' '
            if j == -1:
                print(num_of_rows(board) - (i + 1), end=end_char)
            elif board[i][j] == 0:
                print('*', end=end_char)
            else:
                print(board[i][j], end=end_char)
        print('')


def check_board(board, pieces):
    return vertical_win(board, pieces) or horizontal_win(board, pieces)


def vertical_win(board, pieces):
    if num_of_rows(board) < pieces:
        return False
    # for every column until the last column
    for i in range(0, num_of_rows(board)):
        # for every position in a given column until the bottom row
        for j in range(0, num_of_cols(board)):
            symbol = board[i][j]  # store the symbol
            # if the symbol is equal to 0, that means no piece is at the given position; stop and check the next
            if symbol == 0:
                continue
            num_in_row = 1
            # for every position +1 of the given position until the bottom row
            for k in range(i+1, num_of_rows(board)):
                if symbol == board[k][j]:
                    num_in_row += 1
                    if num_in_row == pieces:
                        return True
                    continue
                else:
                    break
    return False


# check for horizontal win
# strategy: Iterate through every row and iterate every possible starting position in a given row.
#           For every starting position, check if it is a valid symbol. if it is, go to the next starting position.
#           If it is a valid starting position, continue checking the adjacent column(s), recording the number of
#           alike pieces in a row. If this number is equal to the number of pieces required for a win, return True.
#           If a non-alike piece is encountered, go to the next starting position.
#           If there are no more starting positions, and a win has not been encountered, return False.
def horizontal_win(board, pieces):
    if num_of_cols(board) < pieces:
        return False
    # for every row until the last row
    for i in range(0, num_of_rows(board)):
        # for every position in a given row until the last column
        for j in range(0, num_of_cols(board)):
            symbol = board[i][j]  # store the symbol
            # if the symbol is equal to 0, that means no piece is at the given position; stop and check the next
            if symbol == 0:
                continue
            num_in_row = 1
            # for every position +1 of the given position until the last column
            for k in range(j+1, num_of_cols(board)):
                if symbol == board[i][k]:
                    num_in_row += 1
                    if num_in_row == pieces:
                        return True
                    continue
                else:
                    break
    return False


def left_diagonal_win(board, pieces):
    # check that there are enough pieces to get a diagonal win
    if min(num_of_rows(board), num_of_cols(board)) < pieces:
        return False
    if min(num_of_rows(board), num_of_cols(board)) == num_of_rows(board):
        rows_is_min = True
    else:
        rows_is_min = False
    # for every row until the last row
    for i in range(0, num_of_rows(board)):
        # for every position in a given row until the last column
        for j in range(0, num_of_cols(board) - pieces + 1):
            symbol = board[i][j]  # store the symbol
            # if the symbol is equal to 0, that means no piece is at the given position; stop and check the next
            if symbol == 0:
                continue
            # determine diagonal range
            if rows_is_min:
                diagonal_range = num_of_rows(board) - i
            else:
                diagonal_range = num_of_cols(board)
            # if the diagonal range is less than number of pieces to win, break as no more wins can be found
            if diagonal_range < pieces:
                break
            num_in_row = 1
            # for every position +1 of the given position until the last column
            for k in range(j+1, diagonal_range):
                if symbol == board[i][k]:
                    num_in_row += 1
                    if num_in_row == pieces:
                        return True
                    continue
                else:
                    break
    return False


def print_header(board):
    print(' ', end=' ')
    for i in range(0, num_of_cols(board)):
        if i + 1 == num_of_cols(board):
            print(i, end=' ')
        else:
            print(i, end=' ')
    print('')

def check_tie(board):
    count = 0
    for i in range(len(board)):
        for j in board[i]:
            if j == 0:
                count += 1
            if count > 0:
                return False
    return True
# Press the green button in the gutter to run the script.
def main():
    rows = validate_real_number("Enter the number of rows: ")
    columns = validate_real_number("Enter the number of columns: ")
    num_of_pieces = validate_real_number("Enter the number of pieces in a row to win: ")
    grid = [[0 for i in range(columns)] for j in range(rows)]
    game_state = True  # if game_state is true, there is still more game to be played
    game_turn = 1
    print_board(grid)
    while game_state:
        player_move = validate_real_number("Enter the column you want to play in: ", columns)
        board = make_move(grid, player_move, game_turn)
        print_board(grid)
        if check_board(grid, num_of_pieces):
            if player_turn(game_turn) == 'X':
                print('Player 1 won!')
            elif player_turn(game_turn) == 'O':
                print(f'Player 2 won!')
            break
        else:
            if check_tie(board):
                print('Tie Game')
                break
        game_turn += 1


main()