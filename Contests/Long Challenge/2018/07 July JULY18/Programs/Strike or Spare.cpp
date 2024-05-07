#include <cstdio>

void solve()
{
    int length;
    scanf("%d", &length);

    printf("1 1");
    for(int zeroes = 1; 2*zeroes <= length; zeroes++) printf("0");

    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
