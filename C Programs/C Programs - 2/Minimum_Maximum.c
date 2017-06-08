#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define INFINITY 100000 + 1

void solve()
{
    int number_of_numbers, i, current_number, minimum = INFINITY;
    long long total_cost;
    scanf("%d", &number_of_numbers);

    for(i = 1; i <= number_of_numbers; i++)
    {
        scanf("%d", &current_number);
        minimum = min(minimum, current_number);
    }

    total_cost = (number_of_numbers - 1)*1LL*minimum;
    printf("%lld\n",total_cost);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases--)
        solve();

    return 0;
}
