#include <stdio.h>
#define MAX_LENGTH 10000 + 1

void solve(int case_number)
{
    const int DECODER = 0b00000000000000001111111111111111;
    int array_a[MAX_LENGTH], array_b[MAX_LENGTH], number_of_elements, i, num;

    scanf("%d", &number_of_elements);
    for(i = 0; i < number_of_elements; i++)
    {
        scanf("%d", &num);

        array_b[i] = num >> 16; //First 16 digits
        array_a[i] = num&DECODER; //Last 16 digits
    }

    //Output
    printf("Case %d:\n",case_number);
    for(i = 0; i < number_of_elements; i++)
        printf("%d ",array_a[i]);

    printf("\n");
    for(i = 0; i < number_of_elements; i++)
        printf("%d ",array_b[i]);
    printf("\n");
}

int main()
{
    int no_of_test_cases, case_i;
    scanf("%d", &no_of_test_cases);

    for(case_i = 1; case_i <= no_of_test_cases; case_i++)
        solve(case_i);

    return 0;
}
