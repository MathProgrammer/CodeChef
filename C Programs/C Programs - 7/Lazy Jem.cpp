#include <stdio.h>

void solve()
{
    int no_of_problems, break_time;
    int no_of_breaks, problems_solved;
    long long total_time, problem_solving_time = 0LL, problem_solving_minutes;

    scanf("%d %d %lld", &no_of_problems, &break_time, &problem_solving_minutes);

    for(no_of_breaks = 0; no_of_problems != 0; no_of_breaks++, no_of_problems/=2)
    {
        problems_solved = no_of_problems/2 + (no_of_problems%2);

        problem_solving_minutes *= (no_of_breaks == 0 ? 1LL : 2LL);

        problem_solving_time += problems_solved*problem_solving_minutes;
    }

    no_of_breaks--; //We don't take a break after everything is over.

    total_time = problem_solving_time + no_of_breaks*1LL*break_time;
    printf("%lld\n",total_time);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

