#include <stdio.h>

void solve()
{
    int number_of_lamps;
    long long number_of_steps;
    scanf("%d",&number_of_lamps);

    number_of_steps = (number_of_lamps *1LL* (number_of_lamps + 1))/2 + number_of_lamps; //Walk an extra N steps and then N + N-1 + N-2 + ... + 1
    printf("%lld\n", number_of_steps);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
