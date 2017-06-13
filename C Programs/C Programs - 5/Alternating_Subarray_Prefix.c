#include <stdio.h>

#define MAX_LENGTH 100000 + 1
#define true 1
#define false 0

int do_signs_alternate(int a, int b)
{
    if( (a > 0 && b < 0) || (a < 0 && b > 0) )
        return true;
    else
        return false;
}

void solve()
{
    int array[MAX_LENGTH], longest_alternating_subarray_from[MAX_LENGTH], i, number_of_elements;

    scanf("%d", &number_of_elements);
    for(i = 0; i < number_of_elements; scanf("%d", &array[i++]));

    longest_alternating_subarray_from[number_of_elements] =  array[number_of_elements] = 0;

    for(i = number_of_elements - 1; i >= 0; i--)
    {
        longest_alternating_subarray_from[i] = 1 + (do_signs_alternate(array[i], array[i+1]) ? longest_alternating_subarray_from[i + 1] : 0);
    }

    for(i = 0; i < number_of_elements; i++)
        printf("%d ", longest_alternating_subarray_from[i]);

    printf("\n");
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
