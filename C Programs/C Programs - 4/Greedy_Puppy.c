#include <stdio.h>

#define max(a, b) (a > b ? a : b)

void solve()
{
    int number_of_coins, maximum_number_of_people, i, max_remainder = 0;
    scanf("%d %d", &number_of_coins, &maximum_number_of_people);

    for(i = 2; i <= maximum_number_of_people; i++)
        max_remainder = max(max_remainder, number_of_coins%i);

    printf("%d\n",max_remainder);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
