#include <stdio.h>

int main()
{
    unsigned int no_of_test_cases, i, number;
    scanf("%u",&no_of_test_cases);
    for(i = 1; i <= no_of_test_cases; i++)
    {
        /*n = 1, Player 2 wins.
          n = 2, Player 1 wins by taking 1 coin and making it a n = 1 game where he goes second.
          Hypothesis - Player 1 wins on all even n, and Player 2 wins on odd n.
          When Player 1 gets an even number subtract 1. Player 2 gets an odd number. Player 2 can either subtract 1 or any of it's odd divisors.
          So, Player 1 will always get an even number. The number 1 can never be reached in Player 2's turn.
          If Player 1 gets an odd number = 1, Player 1 loses. Otherwise, Player 1 is forced to give Player 2 an even number which Player 2 replicates
          the strategy.*/
        scanf("%u",&number);
        if(number%2 == 0)
        {
            printf("ALICE\n");
        }
        else
        {
            printf("BOB\n");
        }
    }
    return 0;
}
