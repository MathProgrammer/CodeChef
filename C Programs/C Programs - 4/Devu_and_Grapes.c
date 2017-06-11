#include <stdio.h>

#define min(a, b) (a < b ? a : b)

void solve()
{
    int number_of_grapes, k, i, grapes_i;
    long long number_of_operations = 0;
    scanf("%d %d", &number_of_grapes, &k);

    for(i = 1; i <= number_of_grapes; i++)
    {
        scanf("%d", &grapes_i);

        number_of_operations += ( k >= grapes_i ? (k - grapes_i) : min(grapes_i%k, (k - grapes_i%k) ) );
    }

    printf("%lld\n",number_of_operations);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}

