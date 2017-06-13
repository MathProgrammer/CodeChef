#include <stdio.h>

#define MAX_MICROCONTROLLERS 500
#define INFINITY 1e18
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), (max(a, b)%min(a, b)) );
}

long long lcm(int a, int b)
{
    return  (a*1LL*b)/gcd(a, b) ;
}

void solve()
{
    long long min_lcm = INFINITY;
    int number_of_microcontrollers, microcontroller_timing[MAX_MICROCONTROLLERS], i, j;

    scanf("%d", &number_of_microcontrollers);
    for(i = 0; i < number_of_microcontrollers; i++)
        scanf("%d", &microcontroller_timing[i]);

    for(i = 0; i < number_of_microcontrollers; i++)
    {
        for(j = i + 1; j < number_of_microcontrollers; j++)
        {
            min_lcm = min(min_lcm, lcm(microcontroller_timing[i], microcontroller_timing[j]) );
        }
    }

    printf("%lld\n", min_lcm);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}

