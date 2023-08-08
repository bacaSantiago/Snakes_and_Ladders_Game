#include "GameManual.h"

GameManual::GameManual()
{

}

void GameManual::play(){
    char menuOption;
    int initialPos, newPos;
    Player * currentPlayer;
    Tile * currentTile;

    // Loop with switch case until the game is finished, either manually, by number of turns, or a victory
    cout << "\nPress C to continue next turn, or E to end the game: "; // It would be better to display this every turn, but the indications required it to be like this
    do{
        cin >> menuOption;
        switch(toupper(menuOption)){
            case 'E': {
                // Game is finished
                cout << "Thanks for playing!!!" << endl;
                break;
            }
            case 'C': {
                // Game continues

                // Assign the current player based on the number of players and the turn count
                currentPlayer = players[(turnCount - 1) % numPlayers];

                // Saves the initial position before moving for displaying it, then roll the dice and advances the position
                initialPos = currentPlayer -> getCurrentPosition();
                myDice.roll();
                currentPlayer -> move(myDice.getDiceNumber());

                // Condition that checks if the player exceded the board size by the dice value, wich means it already won
                if (currentPlayer -> getCurrentPosition() > board.getSize()){
                    currentPlayer -> setCurrentPosition(board.getSize());
                }    

                // Condition that checks if the tile is a snake or ladder and advances or backs respectively
                currentTile = board.getTile(currentPlayer -> getCurrentPosition()); // Polymorphism
                if (currentTile -> getType() == 'S'){
                    TileSnake* thisSnake = (TileSnake*)currentTile; // Casting a Tile pointer into a TileSnake pointer
                    currentPlayer -> move(thisSnake -> getPenalty());
                }
                else if (currentTile -> getType() == 'L'){
                    TileLadder* thisLadder = (TileLadder*)currentTile; // Casting a Tile pointer into a TileLadder pointer
                    currentPlayer -> move(thisLadder -> getReward()); 
                }

                // Condition that checks if the player exceded the board size by a ladder, wich means it already won
                if (currentPlayer -> getCurrentPosition() > board.getSize()){
                    currentPlayer -> setCurrentPosition(board.getSize());

                }  

                // Condition that checks if a snake made the player exceed the inferior limit of the board, and reubicates to the first position
                if (currentPlayer -> getCurrentPosition() < 1){
                    currentPlayer -> setCurrentPosition(1);
                }

                displayTurnInfo(turnCount, currentPlayer -> getPlayerId(), initialPos, myDice.getDiceNumber(), currentTile -> getType(), currentPlayer -> getCurrentPosition());
                
                // Condition that checks if a player already won
                if (currentPlayer -> getCurrentPosition() == board.getSize()){
                    cout << "Player " << currentPlayer -> getPlayerId() << " is the winner!!!" << endl;
                    menuOption = 'E'; // Is it possible to use 'break' here?
                }

                turnCount++;
                break;
            }
            // Case where the input is neither E or C as expected
            default: {
		        cout << "Invalid option, please press C to continue next turn or E to end the game." << endl; 
                break;
            }
        }
        if (turnCount > maxTurns){ // Important to note that it is printed if the player wins on the last shot. To avoid this, you have to use double conditional with a bool
            cout << "The maximum number of turns has been reached..." << endl;
            menuOption = 'E'; // Is it possible to use 'break' here?
        }
    }
    while (toupper(menuOption)!='E'); // You can also use a 'gamefinished' bool for the do while
    cout << "-- GAME OVER --" << endl;
}
