#include <stdio.h>

void solve()
{
    const int base = 10;
    int sum = 0, number;
    scanf("%d",&number);

    while(number > 0)
    {
        sum += (number%base);
        number /= base;
    }

    printf("%d\n",sum);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
