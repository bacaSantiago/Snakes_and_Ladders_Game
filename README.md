# C++ Snakes and Ladders Game

Author: Santiago Baca

## Introduction

This C++ program simulates a parameterizable version of the classic Snakes and Ladders game. The game board and rules can be configured by the user, and players can compete to reach the final square while encountering snakes and ladders along the way.

## Compilation

Ensure you have a C++ compiler installed on your system (e.g., GCC, Clang).

To compile the program, open a terminal or command prompt, navigate to the directory containing the source files, and run the following command:

```
g++ -std=c++11 *.cpp -o snakes_and_ladders
```

## Execution

After successful compilation, run the program by executing the generated executable:

```
./snakes_and_ladders
```

## Game Rules

- The game board is parameterizable and consists of a fixed number of tiles.
- The board contains a specified number of snake squares (S) and ladder squares (L), randomly placed during initialization.
- Each snake square moves the player back a specified number of squares (penalty).
- Each ladder square advances the player a specified number of squares (reward).
- Players take turns rolling a dice and advancing on the board.
- The game can be played with 1 or 2 players.
- At the beginning of the game, all players start at square 1.
- The game can be played in two modes:
  - **Manual Mode (M):** Players decide whether to continue or end the game at the start of each turn.
  - **Automatic Mode (A):** The game runs automatically until a player wins or reaches the maximum number of turns.
- The game ends when a player reaches or exceeds the final square or when the maximum number of turns is reached.

## Input and Output

The program will prompt the user to configure the game settings:

1. Number of squares on the board.
2. Number of snake squares and their penalty.
3. Number of ladder squares and their reward.
4. Number of players.
5. Maximum number of turns for the game.

After configuring the game, it will display the following menu before the first turn:

```
Press C to continue next turn, or E to end the game:
```

During each turn, the program will display the following information:

```
Turn Player CurrentPosition DiceValue TileType NewPosition
```

Where:
- **Turn:** The current turn number.
- **Player:** The player number taking the turn.
- **CurrentPosition:** The current position of the player.
- **DiceValue:** The result of rolling the dice.
- **TileType:** N for normal boxes, S for snake squares, L for ladder squares.
- **NewPosition:** The position the player will move to after rolling the dice.

The game will end when a player wins, when the maximum number of turns is reached, or when the player enters 'E' during their turn.

The program will display one of the following messages at the end of the game:

- **If a player wins:** `Player [PlayerNumber] is the winner!!!`
- **If the maximum number of turns is reached:** `The maximum number of turns has been reached...`
- **If the player enters 'E':** `Thanks for playing!!!`
- **When the game ends:** `-- GAME OVER --`

## Classes

### Tile

Represents a tile on the board. It can be a normal tile ('N'), a snake tile ('S'), or a ladder tile ('L').

### TileSnake

A subclass of Tile, representing a snake tile. It has an additional attribute `penalty` indicating the number of squares the player goes back when landing on this tile.

### TileLadder

A subclass of Tile, representing a ladder tile. It has an additional attribute `reward` indicating the number of squares the player advances when landing on this tile.

### Board

Represents the game board, consisting of tiles. It is parameterizable, and the number of snakes, ladders, penalties, and rewards can be set.

### Dice

A simple class to simulate the roll of a 6-sided dice.

### Player

Represents a player in the game. It has attributes `playerId` and `currentPosition`, and methods to move the player and get/set player information.

### Game

The main class that orchestrates the game. It has attributes for the board, dice, players, turn count, number of players, and maximum turns. It includes methods for manual and automatic gameplay.

### GameManual

A subclass of Game, representing the manual gameplay. It has a method `play()` that allows the user to control the game's progression.

### GameAuto

A subclass of Game, representing the automatic gameplay. It has a method `play()` that automatically progresses the game.

## Usage

1. Run the program and follow the instructions to set up the game (board size, number of snakes, number of ladders, penalties, rewards, number of players, and maximum turns).
2. Choose between manual or automatic gameplay by entering 'M' or 'A', respectively.
3. If manual gameplay is selected, enter 'C' to continue the game with the next turn or 'E' to end the game at the start of each turn.
4. Observe the turn information displayed for each player, including player number, current position, dice roll, and the type of tile they land on.
5. The game ends when a player reaches or exceeds the final square or when the maximum number of turns is reached. The winner will be displayed at the end of the game.

## Object-Oriented Programming Concepts

The program utilizes the following object-oriented programming concepts:

1. **Class and Object:** The game is represented by a MyGame class, and other classes (e.g., Player, Board, Tile, TileSnake, TileLadder) are used to encapsulate data and behavior for different game elements.

2. **Inheritance:** The TileSnake and TileLadder classes inherit from the Tile class to represent different types of squares on the board.

3. **Polymorphism:** The MyGame class uses polymorphism to handle automatic and manual gameplay by providing specific implementations for each mode.

4. **Composition:** The MyGame class composes instances of the Board, Player, and Dice classes to represent the game components.

## Design Decisions

- The program uses dependency injection to pass configurations to the MyGame class, allowing for flexibility and easier testing.

- Random number generation is used to simulate dice rolls and place snakes and ladders randomly on the board.

- Proper error handling mechanisms can be added to handle exceptional cases, such as incorrect user input.



If you have any questions or need further assistance, feel free to contact me.

Happy gaming!
