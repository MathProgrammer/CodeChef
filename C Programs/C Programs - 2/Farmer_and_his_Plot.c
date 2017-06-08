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
    int length, breadth, gcd_l_b, no_of_squares;
    scanf("%d %d", &length, &breadth);

    gcd_l_b = gcd(length, breadth);

    no_of_squares = (length/gcd_l_b)*(breadth/gcd_l_b);
    printf("%d\n",no_of_squares);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
