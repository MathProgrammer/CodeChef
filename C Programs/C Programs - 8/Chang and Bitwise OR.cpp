#include <cstdio>

void solve()
{
    int no_of_numbers;
    scanf("%d", &no_of_numbers);

    int bitwise_OR = 0, number_i;
    for(int i = 1; i <= no_of_numbers; i++)
    {
        scanf("%d", &number_i);
        bitwise_OR = bitwise_OR|number_i;
    }
    printf("%d\n", bitwise_OR);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
