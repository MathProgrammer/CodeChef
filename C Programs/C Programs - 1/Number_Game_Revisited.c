#include <stdio.h>

int main()
{
    int no_of_test_cases, i, number;
    scanf("%d", &no_of_test_cases);

    /*n = 1, Player 2 wins

    n = 2, Player 1 takes 1 and goes second on a n = 1 game (and wins)
    n = 3, Player 1 takes 2 and goes second on a n = 1 game (and wins)
    n = 4, Player 1 takes 3 and goes second on a n = 1 game (and wins)

    Hypothesis - If n = 1 (mod 4), Player 2 wins
		 		Player 1 wins otherwise
		Let this be true for all n upto n = 4k + 1.

    Induction : n = 4k + 2, 4k + 3, 4k + 4
		Player 1 takes 1, 2, 3 and goes second on n = 4k + 1 and wins by the induction hypothesis

		n = 4(k + 1) + 1, Player 1 can win only by reducing it to a game where n = 1(mod 4)
				The only way of doing that is by subtracting a multiple of 4 from n, which is neither prime nor 1.
		So, n = 4k + 1  is a losing position for Player 1 and Player 2 wins.*/


    for(i = 1; i <= no_of_test_cases; i++)
    {
        scanf("%d", &number);
        if(number%4 == 1)
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
