#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), (max(a, b)%min(a,b) ) );
}

void solve()
{
    int a, b, gcd_a_b;
    long long lcm_a_b;
    scanf("%d %d", &a, &b);

    gcd_a_b = gcd(a, b);
    lcm_a_b = (a*1LL*b)/(gcd_a_b);
    printf("%d %lld\n",gcd_a_b, lcm_a_b);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
