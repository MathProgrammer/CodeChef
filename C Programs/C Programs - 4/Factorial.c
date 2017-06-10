#include <stdio.h>

void solve()
{
    int n_factorial, highest_power_of_5 = 1, exponent_of_5_in_n_factorial = 0;
    scanf("%d", &n_factorial);

    for(highest_power_of_5 = 5; highest_power_of_5 <= n_factorial; highest_power_of_5 *= 5)
    {
        exponent_of_5_in_n_factorial += n_factorial/highest_power_of_5;
    }

    printf("%d\n", exponent_of_5_in_n_factorial);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
