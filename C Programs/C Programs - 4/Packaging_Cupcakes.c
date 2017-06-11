#include <stdio.h>

void solve()
{
    int number_of_cupcakes, divisor_for_maximum_remainder;
    scanf("%d", &number_of_cupcakes);

    divisor_for_maximum_remainder = (number_of_cupcakes/2) + 1;

    printf("%d\n", divisor_for_maximum_remainder);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
