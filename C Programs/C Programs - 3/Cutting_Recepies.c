#include <stdio.h>

#define MAX_INGREDIENTS 50
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    if(a == 1 || b == 1)
        return 1;
    else
        return gcd(min(a, b), max(a, b)%min(a, b));
}

void solve()
{
    int number_of_elements, ingredient[MAX_INGREDIENTS], i, array_gcd;
    scanf("%d", &number_of_elements);

    for(i = 0; i < number_of_elements; i++)
    {
        scanf("%d", &ingredient[i]);

        array_gcd = (i == 0 ? ingredient[i] : gcd(array_gcd, ingredient[i]));
    }

    for(i = 0; i < number_of_elements; i++)
        printf("%d ",ingredient[i]/array_gcd);

    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
