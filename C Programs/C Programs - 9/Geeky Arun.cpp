#include <cstdio>

void solve()
{
    int no_of_pages;
    scanf("%d", &no_of_pages);

    int no_of_days = 1;

    while( (1LL << no_of_days) - 1 < no_of_pages)
        no_of_days++;

    printf("%d\n", no_of_days);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

