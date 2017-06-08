#include <stdio.h>

void solve()
{
    int left, right, odd_number, no_of_appearances_of_odd_divisor;
    long long sum = 0LL;
    scanf("%d %d", &left, &right);

    for(odd_number = 1; odd_number <= right; odd_number += 2)
    {
        no_of_appearances_of_odd_divisor = right/odd_number - (left - 1)/odd_number;
        sum += no_of_appearances_of_odd_divisor*odd_number;
    }
    printf("%lld\n", sum);
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases--)
        solve();

    return 0;
}

