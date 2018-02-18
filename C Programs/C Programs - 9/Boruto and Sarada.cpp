#include <cstdio>

void solve()
{
    long long x, y;
    scanf("%lld %lld", &x, &y);

    long long minimum_sum = (y*(y + 1))/2;
    printf(x >= minimum_sum ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
