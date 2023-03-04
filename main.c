#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

int main(int argc, char* argv[]) {

// Initializes the random generator

srand(time(NULL));

// Sets the player one and player two scores at zero

int player_1= 0;
int player_2= 0;

// Initialize all other required variables

int nRounds, curPlayer;
DiceRound* rounds = NULL;

// Ask the user for the number of rounds to run the game

printf("How many rounds would you like to play? ");
scanf("%d",&nRounds);

// With the user input create array called rounds.

rounds = (DiceRound*)malloc(sizeof(DiceRound)*nRounds);

// This checks to see if the rounds array was created.

if(rounds == NULL) {
    return 1;
}

curPlayer = getRandomNumber(1,2);

// This will fill the DiceRound array through the fillRounds() function

getRoundType(rounds, nRounds);

// Print the initial player scores

printPlayerPoints(player_1,player_2);
for(int i=0;i<nRounds;i++) {
    printf("\nROUND %d\n--------\n", i+1);
    printf("Player\t: %d\n", curPlayer);

    // Print the round information
    
    printRoundInfo(rounds[i]);

// If player one, the even player, is the current player, then the current player gains the points based on what round type it is. The player goes again in the next round.

if(curPlayer == 1 ) {
    if(rounds[i].dice%2 == 0 )
    player_1 += getRoundPoints(rounds[i]);

else
{

// If player one, the even player, is the current player and the dice rolled is odd, then the current player recieves a penalty of the same number of points.
// In the following round, the current player switches to the other player

player_1 -= getRoundPoints(rounds[i]);
curPlayer = 2;
}
}

// If player two, the odd player, is the current player and the dice rolled is odd, then the current player gains the points based on what round type it is. The player goes again in the next round.

else {

// and the dice rolled is odd

if(rounds[i].dice%2 != 0)
player_2 += getRoundPoints(rounds[i]);
else {

// If player two, the odd player, is the current player and the dice rolled is even, then the current player recieves a penalty of the same number of points.
// In the following round, the current player switches to the other player

player_2 -= getRoundPoints(rounds[i]);
curPlayer = 1;
}
}

// This prints the player scores

printPlayerPoints(player_1, player_2);
}

printf("\nGAME OVER!\n");

// Compare player one score and plaer two score
// Print the winner

if(player_1 > player_2)
printf("The winner is Player 1!");
else if(player_1 < player_2)
printf("The winner is Player 2!");
else
printf("Tie!");

// Free the allocated array memory

free(rounds);
rounds = NULL;
return 0;
}