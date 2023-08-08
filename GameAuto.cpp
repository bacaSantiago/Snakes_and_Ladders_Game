#include "GameAuto.h"

GameAuto::GameAuto()
{

}

void GameAuto::play(){
    int initialPos, newPos;
    bool gameFinished = false;
    Player * currentPlayer;
    Tile * currentTile;
    
    // Loop with switch case until the game is finished by number of turns or a victory
    do{
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
            gameFinished = true;
        }

        turnCount++;
        
        // Important to note that it is printed if the player wins on the last shot. To avoid this, use 'else if' and raise the 'turnCount++'
        if (turnCount > maxTurns){
            cout << "The maximum number of turns has been reached..." << endl;
            gameFinished = true;
        }
    }
    while (gameFinished == false);
    cout << "-- GAME OVER --" << endl;
}
