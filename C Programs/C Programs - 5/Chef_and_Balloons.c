#include <stdio.h>

#define min(a, b) (a < b ? a : b)

void solve()
{
    int red, green, blue,  k;
    long long minimum_draws_required = 0;
    scanf("%d %d %d %d", &red, &green, &blue, &k);

    minimum_draws_required = min(k - 1, red);
    minimum_draws_required += min(k - 1, blue);
    minimum_draws_required += min(k - 1, green);

    minimum_draws_required += 1; //Pigeonhole principle

    printf("%lld\n",minimum_draws_required);
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
