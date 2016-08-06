/*
* Ernest Ho 
* Created a game of pig where players roll a dice.
* If the player rolls a number other than 1, the player will add that number to their total score.
* If the player rolls a 1, the total score won for that TURN will be lost.
* (Ex: If score at beginning of turn is 2, and player 1 scores 10 points after and then rolls a 1, the score will revert to 2)
* Players can choose whether or not they want to continue their roll (a gamble) by pressing Y or N.
* First player to 100 points wins.
*/



#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PLAYER1 = 0;
const int PLAYER2 = 1;
const int WINNING_SCORE = 100;

void printIntro() {
    cout << "Welcome to the dice game Pig!" << endl;
    cout << "The objective is to be first to score 100 points." << endl << endl;
}

int humanTurn(string playerName, int playerScore) {
    int roundScore = playerScore;
    int roll;
    char newRoll = 'y';
  
    while(newRoll == 'y') {
        roll = rand()%6+1;
        if (roll == 1 ) {
            cout << playerName << endl << "You rolled a 1 (PIG!)" << endl;
            cout << "Your turn is over" << endl;
            cout << "Your score: " << playerScore << endl << endl;
            return playerScore;
    }
        else {
            roundScore += roll;
            cout << playerName << endl << "You rolled a " << roll << endl;
            cout << "Your score: " << roundScore << endl;
            
            if (roundScore >= WINNING_SCORE) {
                return roundScore;   
            }
            cout << "Do you want to roll again? (y/n): " << endl;
            cin >> newRoll;
        }
    }
    
    return roundScore;
}

int main() {
    srand(4444);

    // setup and initialize variables
    int turn = PLAYER1;
    int player1score = 0;
    int player2score = 0;
    string player1name;
    string player2name;

    printIntro();

    cout << "Player 1 - Enter your name: " << endl;
    cin >> player1name;
    cout << "Player 2 - Enter your name: " << endl;
    cin >> player2name;



    //play game
    while (player1score < WINNING_SCORE && player2score < WINNING_SCORE) {

        //player 1's turn or player 2's turn
         if (turn == PLAYER1) {
            player1score = humanTurn(player1name, player1score);
         }
         else {
            player2score = humanTurn(player2name, player2score);
        }

        //FIXME (3): switch whose turn it is
    if (turn == PLAYER1) {
        turn = PLAYER2;
    }
    else {
        turn = PLAYER1;
    }

    // FIXME (7): Output who won the game.
    if (player1score >= WINNING_SCORE) {
        cout << endl << player1name << " wins!" << endl;
    }
    else if (player2score >= WINNING_SCORE) {
        cout << endl << player2name << " wins!" << endl;
    }

}
    return 0;
}