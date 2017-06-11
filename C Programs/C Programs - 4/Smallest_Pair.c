#include <stdio.h>

#define INFINITY 1e6 + 1

void solve()
{
    int number_of_elements, i, number_i, smallest = INFINITY, second_smallest = INFINITY + 1;
    scanf("%d", &number_of_elements);

    for(i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &number_i);

        if(number_i <= smallest)
        {
            second_smallest = smallest;
            smallest = number_i;
        }
        else if(number_i < second_smallest)
        {
            second_smallest = number_i;
        }
    }

    printf("%d\n", (smallest + second_smallest));
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
