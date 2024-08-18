# ConnectN Project

This project implements the ConnectN game in both C and Python. ConnectN is a game where players take turns to drop pieces into a grid, and the objective is to connect a certain number of pieces in a row, either vertically, horizontally, or diagonally.

## C Version

## Models Included

- ConnectN game logic
- Board management functions

## Getting Started
### Prerequisites
- Ensure you have gcc installed to compile the C code.
  
### Installation

1. Clone the repository:
   
  ```sh
  git clone https://github.com/your-username/repo-name.git
  cd repo-name
```

2. Compile the C code:

  ```sh
  make
  This will generate the connectn.out executable.
```

### Running the Code

3. To run the ConnectN game:

  ```sh
  ./connectn.out <num_rows> <num_cols> <num_pieces>
```
Replace <num_rows>, <num_cols>, and <num_pieces> with the desired values for the game grid dimensions and the number of pieces required to win.

## File Structure

```
├── connectn.c
├── gameboard.c
├── gameplay.c
├── gameboard.h
├── gameplay.h
├── Makefile
└── README.md
```

connectn.c
The main entry point for the C version of the game. It initializes the game and processes command-line arguments.

gameboard.c
Contains functions for printing the game board, checking if columns are empty, and dropping pieces into the board.

gameplay.c
Includes game logic functions, such as validating input, making moves, checking for a win, and handling ties.

Makefile
Automates the build process to compile the C source files into an executable.

## Example Output

```sh
Enter a column between 0 and 6: 3
...
Player 1 Won!
```

## Python Version

### Getting Started

#### Prerequisites
- Ensure you have Python 3.x installed.
  
#### Installation

- No additional libraries are required beyond the standard Python library.

## Running the Code

To run the Python version of ConnectN:

```sh
python connectn.py
```

```
File Structure
├── connectn.py
└── README.md
```

#### connectn.py
The Python implementation of ConnectN. Includes functions for board management, making moves, checking for wins, and handling game state.

```sh
Example Output

Enter the number of rows: 6
Enter the number of columns: 7
Enter the number of pieces in a row to win: 4
...
Player 1 won!
```

## Notes

- The C version provides more detailed gameplay and board management functions.
- The Python version is a simplified implementation suitable for quick testing and development.

## Authors
- Brian Escutia 
