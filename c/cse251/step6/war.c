#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

/*
 * Name : cards.c
 * Program to draw playing cards
 */

/* Function declaration */
void PrintCard(int card, int suit);
void PrintResult(int player1Suit, int player2Suit, int player1Card, int player2Card);

int main()
{
    int player1Suit;
    int player1Card;
    int player2Suit;
    int player2Card;
    bool valid = true;

    /*
     . This seeds the random number
     . generator with the current time
     */
    srand(time(NULL));

    player1Suit = rand() % 4;
    player1Card = rand() % 13 + 1;
    player2Suit = rand() % 4;
    player2Card = rand() % 13 + 1;
    while(valid) {
        if ((player2Suit == player1Suit) && (player2Card == player1Card)) {
            player2Suit = rand() % 4;
            player2Card = rand() % 13 + 1;
            puts("There is a tie");
        }
        else {
            valid = false;
        }
    }

    printf("Player1's card is: ");
    PrintCard(player1Card, player1Suit);
    printf("\n");
    printf("Player2's card is: ");
    PrintCard(player2Card, player2Suit);
    printf("\n");

    PrintResult(player1Suit, player2Suit, player1Card, player2Card);

    printf("\n");
}

void PrintCard(int card, int suit)
{
    switch(card)
    {
    case 1:
        printf("Ace");
        break;

    case 11:
        printf("Jack");
        break;

    case 12:
        printf("Queen");
        break;

    case 13:
        printf("King");
        break;

    default:
        printf("%d", card);
        break;
    }

    printf(" of ");

    switch(suit)
    {
    case 0:
        printf("Hearts");
        break;

    case 1:
        printf("Diamonds");
        break;

    case 2:
        printf("Spades");
        break;

    case 3:
        printf("Clubs");
        break;
    }
}

void PrintResult(int player1Suit, int player2Suit, int player1Card, int player2Card)
{
    if (player1Card == 1) {
        if (player2Card == 1) {
            if (player1Suit < player2Suit) {
                puts("Player 1 wins");
            }
            else {
                puts("Player 2 wins");
            }
        }
        else {
            puts("Player 1 wins");
        }
    }
    else {
        if (player1Card == player2Card) {
            if (player1Suit < player2Suit) {
                puts("Player 1 wins");
            }
            else {
                puts("Player 2 wins");
            }
        }
        else if (player1Card > player2Card) {
            puts("Player 1 wins");
        }
        else if (player2Card == 1) {
            puts("Player 2 wins");
        }
        else {
            puts("Player 2 wins");
        }
    }
}
