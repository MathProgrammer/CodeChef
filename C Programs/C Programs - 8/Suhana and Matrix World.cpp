#include <cstdio>

void solve()
{
    int final_y, final_x, no_of_steps;
    scanf("%d", &no_of_steps);

    final_x =   (no_of_steps/3) + (no_of_steps%3 >= 1);
    final_y = 2*(no_of_steps/3) + (no_of_steps%3 == 2);

    printf("%d %d\n", final_x, final_y);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
