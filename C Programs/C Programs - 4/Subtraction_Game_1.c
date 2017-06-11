#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    if(a == 1 || b == 1)
        return 1;
    else
        return gcd(min(a, b), (max(a, b)%min(a, b)) );
}

void solve()
{
    int number_of_elements, number, i, array_gcd;
    scanf("%d", &number_of_elements);

    for(i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &number);

        array_gcd = (i == 1 ? number : gcd(array_gcd, number));
    }

    printf("%d\n",array_gcd);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
