#include <cstdio>

void solve()
{
    int no_of_solved_problems = 0;

    for(int i = 1; i <= 5; i++)
    {
        int problem_i;
        scanf("%d", &problem_i);

        no_of_solved_problems += problem_i;
    }

    switch(no_of_solved_problems)
    {
        case 0: printf("Beginner\n"); break;
        case 1: printf("Junior Developer\n"); break;
        case 2: printf("Middle Developer\n"); break;
        case 3: printf("Senior Developer\n"); break;
        case 4: printf("Hacker\n"); break;
        case 5: printf("Jeff Dean\n"); break;
    }
}

int main()
{
    int no_of_contestants;
    scanf("%d", &no_of_contestants);

    while(no_of_contestants--)
        solve();

    return 0;
}
