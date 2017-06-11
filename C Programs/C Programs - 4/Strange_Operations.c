#include <stdio.h>

void solve()
{
    int number_of_elements, number_of_operations, parity_of_array = 0, i, number_i;
    scanf("%d %d", &number_of_elements, &number_of_operations);

    for(i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &number_i);
        parity_of_array = parity_of_array + number_i%2;
    }

    /*Case 1: Array sum is even
	The first element inserted is even. All others are odd.

    Case 2: Array sum is odd.
	All inserted elements are even and don't change the sum.*/

    printf( parity_of_array%2 == 0 && number_of_operations == 1 ? "odd\n" : "even\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
