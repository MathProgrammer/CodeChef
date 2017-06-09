#include <stdio.h>

void solve()
{
    int x_lower_limit, x_upper_limit, y_lower_limit, y_upper_limit, x;
    long long no_of_solutions = 0LL;
    scanf("%d %d %d %d",&x_lower_limit, &x_upper_limit, &y_lower_limit, &y_upper_limit);

    for(x = x_lower_limit; x <= x_upper_limit && x <= y_upper_limit; x++)
    {
        no_of_solutions +=  ( x < y_lower_limit ? (y_upper_limit - y_lower_limit + 1) : (y_upper_limit - x) );
    }

    printf("%I64d\n", no_of_solutions);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
