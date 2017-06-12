#include <stdio.h>

#define MAX_LENGTH 10 + 2
#define true 1
#define false 0

void solve()
{
    int i, score_i, score[90] = {0}; //To avoid many if conditions, I am storing the scores in an array of length 90, indexed by the first alphabet.
                                     //This does mean that 90 - 4 memory locations will be wasted.
    char team[MAX_LENGTH];

    for(i = 1; i <= 4; i++)
    {
        scanf("%s %d", team, &score_i);
        score[team[0]] = score_i;
    }


    printf(score['B'] > score['E'] && score['M'] > score['R'] ? "Barcelona\n" : "RealMadrid\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
