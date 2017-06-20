#include <stdio.h>

#define MAX_LENGTH 50 + 1

void solve()
{
    int number_of_alternating_segments = 0, i;
    char crayons[MAX_LENGTH], previous_orientation = 'X';

    scanf("%s", crayons);
    for(i = 0; crayons[i] != '\0'; i++)
    {
        if(crayons[i] != previous_orientation)
            number_of_alternating_segments++;

        previous_orientation = crayons[i];
    }

    printf("%d\n", number_of_alternating_segments/2);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
