#include <stdio.h>

void solve()
{
    int no_of_points, xor_all_numbers = 0, i, x, y;
    scanf("%d", &no_of_points);
    for(i = 1; i <= no_of_points; i++)//This doesn't really matter.
        scanf("%d %d", &x, &y);

    for(i = 1; i <= no_of_points; i++)
    {
        xor_all_numbers = xor_all_numbers^i;
    }
    printf("%d\n",xor_all_numbers);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases--)
        solve();

    return 0;
}
