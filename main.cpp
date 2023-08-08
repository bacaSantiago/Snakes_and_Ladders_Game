#include "GameManual.h"
#include "GameAuto.h"

int main(){
    int size, numSnakes, sPenalty, numLadders, lReward, numPlayers, maxTurns;
    char gameType;

    cout << "\nWelcome to the Snake and Ladders game! The objective of the game is simple: be the first player to reach the final square on the board. \nPlease, enter the requested information to set up your experience :)." << endl << endl;
    
    // Ask for board size
    do
    {
        cout << "Set the size of the board: ";
        cin >> size;
        // Condition to make sure the board size is a value that the game supports
        if (size <= 0){
            cout << "Board size cannot be negative or equal to zero. Try again." << endl;
        }
        
    } while (size <= 0);

    // Ask for number of snakes and its penalty
    cout << "\nType the number of snakes on the board, as well as the amount of tiles the player moves back." << endl;
    do
    {
        cout << "Number of snakes: "; cin >> numSnakes;
        cout << "Penalty tiles (negative number): "; cin >> sPenalty;
        // Condition to make sure the amounts are values that the game supports
        if (numSnakes < 0 || sPenalty > 0){
            cout << "The penalty canot be positive, while the amount of snakes should be positive. Try again." << endl;
        }
    } while (numSnakes < 0 || sPenalty > 0);
    
    // Ask for number of ladders and its reward
    cout << "\nType the number of ladders on the board, as well as the amount of tiles the player advances." << endl;
    do
    {
        cout << "Number of ladders: "; cin >> numLadders;
        cout << "Reward tiles: "; cin >> lReward;
        // Condition to make sure the amounts are values that the game supports
        if (numLadders < 0 || lReward < 0){
            cout << "They canot be negative amounts. Try again." << endl;
        }
    } while (numLadders < 0 || lReward < 0);

    // Ask for number of players
    cout << endl;
    do
    {
        cout << "Enter the number of players, you can play either a solo game, or multiplayer with as many players as you wish: ";
        cin >> numPlayers;
        // Condition to make sure the number of players is not negative
        if (numPlayers <= 0){
            cout << "Invalid number of players. Try again." << endl;
        }
    } 
    while (numPlayers <= 0);

    // Ask for maximum of turns
    cout << endl;
    do
    {
        cout << "Also, state the maximum number of game turns per player: "; 
        cin >> maxTurns;
        // Condition to make sure the maximum of turns is a value that the game supports
        if (maxTurns <= 0){
            cout << "Turns cannot be negative or equal to zero. Try again." << endl;
        }
    } while (maxTurns <= 0);
    maxTurns *= numPlayers; // Multiply the number of game turns per player by the number of players

    // Ask for type of mode
    cout << "\nFinally, what game mode do you want to play? Press: \n - 'A' for automatic.\n - 'M' for manual." << endl;
    do
    {
        cout << "Your choice: "; cin >> gameType;
        gameType = toupper(gameType);
        // Condition to make sure the input is either A or M as expected
        if (gameType != 'A' && gameType != 'M'){
            cout << "Invalid option, please press A for automatic or M for manual game mode." << endl;
        }
    } while (gameType != 'A' && gameType != 'M');
    
    cout << "\nAlright, all set to play. Enjoy it and have a great time playing!" << endl;

    // Create a Game instance
    Game * myGame = new Game(size, numSnakes, sPenalty, numLadders, lReward, numPlayers, maxTurns);
    if (gameType == 'A'){
        GameAuto* autoMyGame = (GameAuto*)myGame; // Casting a Game pointer into a GameAuto pointer
        autoMyGame -> play();
    }
    else if (gameType == 'M'){
        GameManual* manualMyGame = (GameManual*)myGame; // Casting a Game pointer into a GameManual pointer
        manualMyGame -> play();
    }
    
    return 0;
}
