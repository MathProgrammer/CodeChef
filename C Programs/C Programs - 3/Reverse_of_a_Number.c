#include <stdio.h>

void solve()
{
    const int base = 10;
    int reverse = 0, number;
    scanf("%d",&number);

    while(number > 0)
    {
        reverse = reverse*base + (number%base);
        number /= base;
    }

    printf("%d\n",reverse);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
