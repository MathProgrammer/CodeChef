#include <stdio.h>

void solve()
{
    int number_of_numbers, k, number_of_even_numbers = 0, i, number_i;
    scanf("%d %d", &number_of_numbers, &k);

    for(i = 1; i <= number_of_numbers ; i++)
    {
        scanf("%d", &number_i);
        number_of_even_numbers += (number_i%2 == 0 ? 1 : 0);
    }

    //If k = 0, and all the numbers are even, Chef cannot give a gift
    printf(number_of_even_numbers < k || (k == 0 && number_of_even_numbers == number_of_numbers) ? "NO\n" : "YES\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
