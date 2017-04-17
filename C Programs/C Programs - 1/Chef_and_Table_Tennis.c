#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10001
int count_no_of_wins(char []);

int main()
{
    int no_of_test_cases, i, no_of_wins, no_of_losses;
    char points[MAX_LENGTH];
    scanf("%d",&no_of_test_cases);

    for(i = 1; i <= no_of_test_cases; i++)
    {
        scanf("%s", points);
        no_of_wins = count_no_of_wins(points);
        no_of_losses = strlen(points) - no_of_wins;

        printf( (no_of_wins > no_of_losses ? "WIN\n" : "LOSE\n"));
    }
    return 0;
}

int count_no_of_wins(char points[])
{
    int i, no_of_wins = 0;
    for(i = 0; points[i]!= '\0'; i++)
    {
        if(points[i] == '1')
        {
            no_of_wins++;
        }
    }
    return no_of_wins;
}
