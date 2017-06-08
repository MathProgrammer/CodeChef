#include <stdio.h>

void solve()
{
    int number, number_of_4s = 0;
    scanf("%d", &number);

    while(number > 0)
    {
        number_of_4s += (number%10 == 4 ? 1 : 0);
        number = number/10;
    }
    printf("%d\n",number_of_4s);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases--)
        solve();

    return 0;
}
