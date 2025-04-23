# Snakes and Ladders (Command Line)

This is a simple command-line implementation of the classic board game Snakes and Ladders, written in C++. It allows a single player to play against the random chance of the dice, navigating snakes and climbing ladders to reach the final square.

## Features

* **Classic 10x10 Board:** The game is played on a standard 100-square board.
* **Snakes and Ladders:** Includes predefined snake and ladder positions that transport the player to different squares.
* **Dice Roll:** Simulates rolling a standard six-sided die for movement.
* **Player Movement Visualization:** Shows the player's position on the board after each move.
* **Game Progression:** Tracks the player's position and determines the win condition.
* **Basic User Interaction:** Requires the user to press Enter to proceed with each turn.

## Getting Started

### Prerequisites

To compile and run this game, you will need:

* A C++ compiler (like g++).
* A terminal or command prompt that supports ANSI escape codes for colored output (common on Linux/macOS terminals, and can be enabled on some Windows terminals).

### Compiling and Running

1.  Save the provided C++ code as a `.cpp` file (e.g., `snakes_ladders.cpp`).
2.  Open a terminal or command prompt.
3.  Navigate to the directory where you saved the file.
4.  Compile the program using your C++ compiler. For example, with g++:

    ```bash
    g++ snakes_ladders.cpp -o snakes_ladders
    ```

5.  Run the compiled program:

    ```bash
    ./snakes_ladders
    ```

## How to Play

1.  Upon starting the game, you will see the initial board with your position marked.
2.  Press `Enter` to roll the dice.
3.  The program will display the number rolled and your character will move square by square to the new position.
4.  If you land on the head of a snake, you will slide down to its tail.
5.  If you land on the bottom of a ladder, you will climb up to the top.
6.  You must land exactly on square 100 to win. If your dice roll would take you beyond 100, your turn is skipped.
7.  Continue pressing `Enter` for each turn until you reach square 100.

## How it Works (Behind the Scenes)

* The game board is represented by a 2D array (`board[10][10]`).
* The positions of snakes and ladders are stored in `std::map` containers (`snakes` and `ladders`). The keys are the starting squares (snake head or ladder bottom), and the values are the ending squares (snake tail or ladder top).
* The `setBoard()` function initializes the board with numbers from 100 down to 1 in a zig-zag pattern to match the visual layout of a typical Snakes and Ladders board. It also defines the snake and ladder positions.
* The `currentBoard()` function is responsible for printing the current state of the board with the player's position highlighted. It includes a small delay and clears the screen to give a sense of animation during movement.
* The `main()` function manages the game loop:
    * It initializes the player's position to 1.
    * It generates a random number between 1 and 6 to simulate a dice roll.
    * It checks if the move is valid (doesn't exceed 100).
    * It updates the player's position and checks if they landed on a snake or ladder.
    * It calls `currentBoard()` to display the updated position.
    * The game continues until the player reaches position 100.

## Acknowledgments

This project was a fun exercise in implementing a classic game using C++ fundamentals, including arrays, maps, loops, and basic input/output.
