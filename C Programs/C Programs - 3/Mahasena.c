#include <stdio.h>

int main()
{
    int no_of_soldiers, no_of_lucky_soldiers = 0, no_of_unlucky_soldiers = 0, weapons_of_soldier, i;
    scanf("%d", &no_of_soldiers);

    for(i = 1; i <= no_of_soldiers; i++)
    {
        scanf("%d", &weapons_of_soldier);

        no_of_unlucky_soldiers += (weapons_of_soldier%2);
    }
    no_of_lucky_soldiers = no_of_soldiers - no_of_unlucky_soldiers;

    printf(no_of_lucky_soldiers > no_of_unlucky_soldiers ? "READY FOR BATTLE\n" : "NOT READY\n");

    return 0;
}
