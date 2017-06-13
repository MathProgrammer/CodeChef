#include <stdio.h>

#define MAX_LENGTH 50 + 1

void solve()
{
    int numbers[MAX_LENGTH];
    int number_of_elements, i, j, sum, product, number_of_good_subarrays = 0; //A subarray is said to be good if it's sum = product

    scanf("%d", &number_of_elements);
    for(i = 0; i < number_of_elements; i++)
        scanf("%d", &numbers[i]);

    for(i = 0; i < number_of_elements; i++)
    {
        sum = 0;
        product = 1;

        for(j = i; j >= 0; j--)
        {
            sum += numbers[j];
            product *= numbers[j];

            number_of_good_subarrays += (sum == product);
        }

    }

    printf("%d\n", number_of_good_subarrays);
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
