#include <stdio.h>

#define MAX_BALLS 100000 + 1

void solve()
{
    char ball_line_1[MAX_BALLS], ball_line_2[MAX_BALLS];
    int i;
    scanf("%s %s",ball_line_1, ball_line_2);

    for(i = 0; ball_line_1[i] != '\0'; i++)
    {
        if(ball_line_1[i] == ball_line_2[i])
        {
            if(ball_line_1[i] == 'W')
                printf("B");
            else
                printf("W");
        }
        else
        {
            printf("B"); //Doesn't matter ... Can be B as well
        }
    }

    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
