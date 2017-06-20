#include <stdio.h>

int is_power_of_2(int n)
{
    if( ( n&(n - 1) ) == 0)
        return true;
    else
        return false;
}

void solve()
{
    int n;
    scanf("%d", &n);

    if(n == 1)
        printf("2\n");
    else
        printf("%d\n", is_power_of_2(n + 1) ? (n >> 1) : -1);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
