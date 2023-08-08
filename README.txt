**Snakes and Ladders Game**
Coder: Alejandro Santiago Baca Eyssautier

Instructions for Compiling and Running the Program:

1. Compilation:
   - Ensure you have a C++ compiler installed on your system (e.g., GCC, Clang).
   - Open a terminal/command prompt and navigate to the directory containing the source files.
   - Compile the program using the following command:
       $ g++ *.cpp -o snakes_and_ladders -std=c++11

2. Execution:
   - After successful compilation, run the program by executing the generated executable:
       $ ./snakes_and_ladders

Game Rules:
- The game supports 1 or 2 players.
- Each player starts at box 1.
- Players take turns rolling a dice and advancing on the board.
- Snakes (S) cause the player to move back 3 squares by default.
- Ladders (L) allow the player to move forward 3 squares by default.
- The game ends when a player reaches or exceeds the final square.
- Players can set the maximum number of turns, amount of snakes and ladders, and its penalty or reward, as well as the board size
- Players can choose to continue the game or end it at the start of each turn.
- Also, players can choose between automatic and manual game mode

Object-Oriented Programming Concepts Used:
1. Class and Object: The game is designed using several classes, such as Player, Board, Tile, TileSnake, TileLadder, Dice, Game, GameAuto, and GameManual, to encapsulate related data and behavior.
2. Inheritance: The GameAuto and GameManual classes inherit common functionality from the Game class, as well as TileSnake and TileLadder do from the Tile Class.
3. Composition: The Game class contains instances of the Board, Player, and Dice classes to compose the game's components. The Board class contains instances of Tile to compose the board's components.
4. Encapsulation: Each class encapsulates its own data and provides public interfaces for interacting with the data.
5. Polymorphism: The Game class casts into the GameAuto and GameManual classes, as well as Tile class casts into TileSnake and TileLadder classes, to provide specific implementations for automatic and manual gameplay. 

Design Decisions and Justification:
- Separation of Concerns: The game logic is divided into different classes to separate responsibilities and improve modularity.
- Dependency Injection: The Game class accepts instances of Tiles, Board, Player, and Dice through its constructor, allowing for flexibility and easier testing.
- Random Number Generation: A random number generator is used to simulate dice rolls, providing a different value each time the program is run.
- Consistent Naming Conventions: The classes, methods, and variables are named descriptively to enhance code readability and maintainability.
- Random Number Generation: A random number generator is used to simulate dice
- Error Handling: Proper error handling mechanisms can be added to handle exceptional cases, such as incorrect user input.

Enjoy playing Snakes and Ladders!
