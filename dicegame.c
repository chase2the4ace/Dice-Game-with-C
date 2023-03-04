#include "dicegame.h"
#include <stdio.h>
#include <stdlib.h>

//The function intakes two integer parameters called min and max,

int getRandomNumber(int min, int max) {
    return rand()%(max-min+1)+min;
}

//The function intakes two parameters: DiceRound dynamic array and size of the array.

void getRoundType(DiceRound *rounds, int size) {
    int i;
    for(i=0;i<size;i++)
    {

// This gives the dice a value between one and six

rounds[i].dice = getRandomNumber(1,6);

// assign points between 10-100 (inclusive) in multiples of 10

rounds[i].points = getRandomNumber(0,9)*10;
int n = getRandomNumber(0,9); // get a random number between [0,9]

//The random number decides the round type

if(n <= 2)
rounds[i].type = BONUS;
else if(n <= 4)
rounds[i].type = DOUBLE;
else
rounds[i].type = REGULAR;
}
}

//The function intakes one parameter which is one DiceRound object and will return the points for the round.

int getRoundPoints(DiceRound round) {
    if(round.type == BONUS)
    return 100;
    else if(round.type == DOUBLE)
    return 2*round.points;
    else
    return round.points;
    }

//The function intakes one parameter which is a DiceRound object for the round

void printRoundInfo(DiceRound round) {
    printf("\nType: ");
    if(round.type == BONUS)
    printf("BONUS");
    else if(round.type == REGULAR)
    printf("REGULAR");
    else
    printf("DOUBLE");
    printf("\nDICE: %d",round.dice);
    printf("\nPOINTS: %d\n",round.points);
    }


//The function intakes two integer parameters, both being player scores

void printPlayerPoints(int player_1, int player_2) {
    printf("\nP-1 : %d",player_1);
    printf("\nP-2 : %d\n",player_2);
    }