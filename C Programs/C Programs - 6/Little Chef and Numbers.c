#include <stdio.h>

void solve()
{
    int number_of_greater_than_1 = 0, number_of_2 = 0, number_i, i, number_of_elements;
    long long no_of_pairs;
    scanf("%d", &number_of_elements);

    for(i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &number_i);
        number_of_greater_than_1 += (number_i > 1);
        number_of_2 += (number_i == 2);
    }

    if(number_of_2 == number_of_greater_than_1)
        no_of_pairs = 0;
    else
        no_of_pairs = (number_of_greater_than_1*1LL*(number_of_greater_than_1 - 1) )/2 - (number_of_2*1LL*(number_of_2 - 1) )/2;

    printf("%lld\n", no_of_pairs);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();
    return 0;
}
