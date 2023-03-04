#ifndef DICEGAME_H
#define DICEGAME_H

typedef enum ROUNDTYPE { BONUS, DOUBLE, REGULAR } ROUNDTYPE;

typedef struct DiceRound
{
int dice;
int points;
ROUNDTYPE type;
}DiceRound;

int getRandomNumber(int min, int max);
void getRoundType(DiceRound *rounds, int size);
int getRoundPoints(DiceRound dice);
void printRoundInfo(DiceRound dice);
void printPlayerPoints(int p1, int p2);

#endif // DICEGAME_H