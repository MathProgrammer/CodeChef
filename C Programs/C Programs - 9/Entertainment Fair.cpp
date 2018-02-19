#include <cstdio>

long long sum_till(long long n)
{
    return (n*(n + 1))/2;
}

void solve()
{
    long long no_of_doughnuts;
    scanf("%lld", &no_of_doughnuts);

    const int DOUGHNUTS_IN_A_BOX = 7;
    long long no_of_boxes = no_of_doughnuts/DOUGHNUTS_IN_A_BOX;

    long long no_of_summersaults = sum_till(no_of_boxes)*DOUGHNUTS_IN_A_BOX;

    printf("%lld\n", no_of_summersaults);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

